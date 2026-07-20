#include <Arduino.h>
#include <U8g2lib.h>
#include <PID_v1.h>
#include <Encoder.h>

// --- PINS SEGUNDO O TEU ESQUEMA ---
#define PIN_TRIAC 13
#define PIN_NTC A3//A0
#define PIN_ENC_A 2
#define PIN_ENC_B 3
#define PIN_ENC_SW 4

// --- LÍMITES DE SEGURIDADE ---
#define TEMP_MAX_SEGURA 325.0
#define SENSOR_MIN 5    // Curto
#define SENSOR_MAX 1018 // Aberto

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Encoder myEnc(PIN_ENC_A, PIN_ENC_B);

double setpoint = 200; // Temperatura inicial axustada a 200C
double input = 0, output = 0;
bool sistemaActivo = false;
bool erroCritico = false;

// PID: Kp, Ki, Kd (Valores base para plancha térmica)
double Kp=2, Ki=0.5, Kd=2;
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

float lerTemperatura() {
  int raw = analogRead(PIN_NTC);
  if (raw < SENSOR_MIN || raw > SENSOR_MAX) { erroCritico = true; return 999.0; }
  
  float resistencia = 47000.0 / (1023.0 / (float)raw - 1.0);
  float temp = 1 / (1 / (273.15 + 25) + log(resistencia / 100000.0) / 3950.0);
  float celsius = temp - 273.15;
  if (celsius > TEMP_MAX_SEGURA) erroCritico = true;
  return celsius;
}

void setup() {
  pinMode(PIN_TRIAC, OUTPUT);
  digitalWrite(PIN_TRIAC, LOW);
  pinMode(PIN_ENC_SW, INPUT_PULLUP);
  u8g2.begin();
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255);
  myPID.SetSampleTime(500); 
}

void loop() {
  input = lerTemperatura();

  // 1. CONTROL DE ENCENDIDO/APAGADO
  if (digitalRead(PIN_ENC_SW) == LOW) {
    delay(300); // Debounce
    sistemaActivo = !sistemaActivo;
    if (sistemaActivo) {
      setpoint = 200; // Reseteamos a 200C ao acender
    } else {
      digitalWrite(PIN_TRIAC, LOW);
      output = 0;
    }
  }

  // 2. LÓXICA DE CONTROL
  if (sistemaActivo && !erroCritico) {
    long steps = myEnc.read() / 4;
    if (steps != 0) {
      setpoint = constrain(setpoint + steps, 0, 300);
      myEnc.write(0);
    }
    myPID.Compute();
    analogWrite(PIN_TRIAC, output);
  } else {
    digitalWrite(PIN_TRIAC, LOW);
  }

  // 3. PANTALLA (MODO PÁXINA PARA BAIXA RAM)
  u8g2.firstPage();
  do {
    if (erroCritico) {
      u8g2.setFont(u8g2_font_9x15_tr);
      u8g2.drawStr(10, 35, "ERRO SENSOR!");
    } else {
      // Temp Actual
      u8g2.setFont(u8g2_font_logisoso32_tf);
      u8g2.setCursor(0, 42);
      u8g2.print((int)input); u8g2.print("C");
      
      // Info PWM á dereita
      u8g2.setFont(u8g2_font_6x12_tr);
      u8g2.setCursor(85, 25); u8g2.print(F("PWR:"));
      u8g2.setCursor(85, 40); u8g2.print(map(output, 0, 255, 0, 100)); u8g2.print(F("%"));

      // Barra e Setpoint
      u8g2.drawFrame(0, 48, 128, 6);
      u8g2.drawBox(0, 48, map(output, 0, 255, 0, 128), 6);
      u8g2.setCursor(0, 62);
      u8g2.print(F("SET: ")); u8g2.print((int)setpoint); u8g2.print(F("C"));
      u8g2.setCursor(95, 62);
      u8g2.print(sistemaActivo ? F("ON") : F("OFF"));
    }
  } while ( u8g2.nextPage() );
}
