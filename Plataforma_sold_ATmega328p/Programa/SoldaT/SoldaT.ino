#include <Arduino.h>
#include <U8g2lib.h>
#include <PID_v1.h>
#include <Encoder.h>

// --- PINS SEGUNDO O TEU ESQUEMA ---
#define PIN_TRIAC 13
#define PIN_NTC A3
#define PIN_ENC_A 2
#define PIN_ENC_B 3
#define PIN_ENC_SW 4

// --- LÍMITES DE SEGURIDADE ---
#define TEMP_MAX_SEGURA 325.0
#define SENSOR_MIN 5     // Curto
#define SENSOR_MAX 1018  // Aberto

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Encoder myEnc(PIN_ENC_A, PIN_ENC_B);

double setpoint = 200; // Temperatura inicial axustada a 200C
double input = 0, output = 0;
bool sistemaActivo = false;
bool erroCritico = false;

// --- PARAMETROS PID E OFFSET ---
double Kp = 0.50, Ki = 0.03, Kd = 10.0;
double tempOffset = -7.0; 

PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// --- ESTATOS DE MENÚ ---
enum ModoPantalla { MODO_PRINCIPAL, MODO_MENU_PID };
ModoPantalla modoActual = MODO_PRINCIPAL;
int opcionMenu = 0; // 0: Kp, 1: Ki, 2: Kd, 3: Offset

// Variables para xestionar a pulsación longa/curta do botón
unsigned long tempoBotonPresionado = 0;
bool botonPremido = false;

float lerTemperatura() {
  int raw = analogRead(PIN_NTC);
  if (raw < SENSOR_MIN || raw > SENSOR_MAX) { erroCritico = true; return 999.0; }
  
  float resistencia = 47000.0 / (1023.0 / (float)raw - 1.0);
  float temp = 1 / (1 / (273.15 + 25) + log(resistencia / 100000.0) / 3950.0);
  float celsius = temp - 273.15;
  
  // Aplicamos o Offset de calibración
  celsius += tempOffset;

  if (celsius > TEMP_MAX_SEGURA) erroCritico = true;
  return celsius;
}

void setup() {
  pinMode(PIN_TRIAC, OUTPUT);
  digitalWrite(PIN_TRIAC, LOW);
  pinMode(PIN_ENC_SW, INPUT_PULLUP);
  u8g2.begin();
  
  myPID.SetTunings(Kp, Ki, Kd);
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255);
  myPID.SetSampleTime(500); 
}

void loop() {
  input = lerTemperatura();

  // 1. XESTIÓN DO BOTÓN (Pulsación curta / Pulsación longa)
  int estadoBoton = digitalRead(PIN_ENC_SW);
  
  if (estadoBoton == LOW && !botonPremido) {
    botonPremido = true;
    tempoBotonPresionado = millis();
  } 
  else if (estadoBoton == HIGH && botonPremido) {
    botonPremido = false;
    unsigned long duracion = millis() - tempoBotonPresionado;

    if (duracion > 1500) { 
      // PULSACIÓN LONGA: Entrar / Saír do Menú PID
      if (modoActual == MODO_PRINCIPAL) {
        modoActual = MODO_MENU_PID;
        opcionMenu = 0;
      } else {
        modoActual = MODO_PRINCIPAL;
      }
      myEnc.write(0);
    } else if (duracion > 50) { 
      // PULSACIÓN CURTA
      if (modoActual == MODO_PRINCIPAL) {
        // Acender / Apagar
        sistemaActivo = !sistemaActivo;
        if (sistemaActivo) {
          setpoint = 200;
        } else {
          digitalWrite(PIN_TRIAC, LOW);
          output = 0;
        }
      } else {
        // No menú: Cambiar entre Kp -> Ki -> Kd -> Offset
        opcionMenu = (opcionMenu + 1) % 4;
      }
      myEnc.write(0);
    }
  }

  // 2. LÓXICA DE CONTROL E NAVEGACIÓN DO ENCODER
  long steps = myEnc.read() / 4;
  if (steps != 0) {
    if (modoActual == MODO_PRINCIPAL) {
      if (sistemaActivo && !erroCritico) {
        setpoint = constrain(setpoint + steps, 0, 300);
      }
    } else {
      // Axuste dos parámetros do menú PID
      switch (opcionMenu) {
        case 0: Kp = max(0.0, Kp + steps * 0.05); break;
        case 1: Ki = max(0.0, Ki + steps * 0.01); break;
        case 2: Kd = max(0.0, Kd + steps * 0.5);  break;
        case 3: tempOffset += steps * 0.5;        break;
      }
      myPID.SetTunings(Kp, Ki, Kd); // Actualiza o PID
    }
    myEnc.write(0);
  }

  // Lóxica do PID / Triac
  if (sistemaActivo && !erroCritico) {
    myPID.Compute();
    analogWrite(PIN_TRIAC, output);
  } else {
    digitalWrite(PIN_TRIAC, LOW);
  }

  // 3. DESEÑO DA PANTALLA
  u8g2.firstPage();
  do {
    if (erroCritico) {
      u8g2.setFont(u8g2_font_9x15_tr);
      u8g2.drawStr(10, 35, "ERRO SENSOR!");
    } 
    else if (modoActual == MODO_MENU_PID) {
      // --- PANTALLA DO MENÚ PID (Como na túa foto) ---
      u8g2.setFont(u8g2_font_7x14_tr);
      u8g2.drawStr(0, 12, "MENU PID");

      u8g2.setCursor(0, 28);
      u8g2.print(opcionMenu == 0 ? F(">Kp: ") : F(" Kp: "));
      u8g2.print(Kp, 2);

      u8g2.setCursor(0, 40);
      u8g2.print(opcionMenu == 1 ? F(">Ki: ") : F(" Ki: "));
      u8g2.print(Ki, 2);

      u8g2.setCursor(0, 52);
      u8g2.print(opcionMenu == 2 ? F(">Kd: ") : F(" Kd: "));
      u8g2.print(Kd, 1);

      u8g2.setCursor(0, 64);
      u8g2.print(opcionMenu == 3 ? F(">Offset: ") : F(" Offset: "));
      u8g2.print(tempOffset, 1);
    } 
    else {
      // --- PANTALLA PRINCIPAL ---
      u8g2.setFont(u8g2_font_logisoso32_tf);
      u8g2.setCursor(0, 42);
      u8g2.print((int)input); u8g2.print("C");
      
      u8g2.setFont(u8g2_font_6x12_tr);
      u8g2.setCursor(85, 25); u8g2.print(F("PWR:"));
      u8g2.setCursor(85, 40); u8g2.print(map(output, 0, 255, 0, 100)); u8g2.print(F("%"));

      u8g2.drawFrame(0, 48, 128, 6);
      u8g2.drawBox(0, 48, map(output, 0, 255, 0, 128), 6);
      u8g2.setCursor(0, 62);
      u8g2.print(F("SET: ")); u8g2.print((int)setpoint); u8g2.print(F("C"));
      u8g2.setCursor(95, 62);
      u8g2.print(sistemaActivo ? F("ON") : F("OFF"));
    }
  } while ( u8g2.nextPage() );
}