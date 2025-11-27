# Controlador de placa para soldar
<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/Plataforma_soldadora_.png" width="300" align="right">
> [!NOTE]
> Documentación en galego

Tratase dun **controlador térmico intelixente** de placa calefactora 230Vac para soldar/desoldar,
deseÃ±ado para uso persoal, educativo e experimental. Baseado en ESP32-C3, permite:

- Axuste preciso da temperatura (300ºC).
- Control "P" simple e estable.
- Detección de fallos do termistor.
- Gráfico en tempo real da temperatura.
- Indicador ON/OFF e potencia aplicada o calefactor na pantalla.
- Corte de emerxencia por sobrecalentamento (300°C).
- Illamento galvánico (mico-fonte de alimentación conmutada)
- Control mediante SSR (Triack) a 230Vac

Saú2.

## [Versión 001]

<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/Plataforma_soldadora_2.png" width="300" align="left">
<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/certification-mark-ES000055-stacked.png" width="300" align="right">





## Listado de Compoñentes (BOM)

| Qty | Value        | Device                            | Package                      | Parts            | Description        |
|-----|--------------|-----------------------------------|------------------------------|------------------|--------------------|
| 1   |              | AK500/4-H                         | AK500/4-H                    | X1               | CONNECTOR          |
| 1   |              | LED3MM                            | LED3MM                       | LED1             | LED 3mm RED        |
| 3   | 10K          | R-EU_R0603                        | R0603                        | R6, R7, R8       | RESISTOR           |
| 1   | 10R          | R-EU_R0603                        | R0603                        | R1               | RESISTOR           |
| 1   | 10nF/400V    | C-EU075-042X103                   | C075-042X103                 | C1               | CAPACITOR          |
| 1   | 10uF         | C-EUC1206K                        | C1206K                       | C2               | CAPACITOR          |
| 1   | 22-27-2021-02| 22-27-2021-02                     | 6410-02                      | J1               | CONNECTOR Molex    |
| 2   | 390R         | R-EU_0204/7                       | 0204/7                       | R2, R3           | RESISTOR           |
| 1   | 39R          | R-EU_0204/7                       | 0204/7                       | R4               | RESISTOR           |
| 1   | 47K          | R-EU_R0603                        | R0603                        | R5               | RESISTOR           |
| 1   | BTA06400B    | BTA06400B                         | TO220AB                      | T1               | Triac BTA          |
| 1   |              | DISPLAY-OLED-128X128-I2C          | DISPLAY-OLED-1,5 pulgadas    | OLED             |SDA, SCL, GND, VCC  |
| 1   |              | ESP32-C3_SUPERMINISMD             | [ESP32 C3 Supermini]:        | U5               |                    |
| 1   |              | FUS 5A                            | 8,5x4                        | F1               | Fuse 5A            |
| 1   |              | MOC3041                           | IL410                        | OK1              | OPTO COUPLER       |
| 1   |              | ROTARTY_ENCODER                   | [ROTARTY_ENCODER]            | SW2              | Rotary encoder     |
| 1   |              | RPDZN5W6H                         | [RPDZN5W6H]                  | U1               | AC-DC 5V 700mA     |




## Deseñado en Estrimia con agarimo.

### Author and license
* Author: XDeSIG [No Twitter, no X]
* License: [CERN Open Hardware Licence Version 2 - S - Reciprocal][CERN-OHL-W]
* Open Hardware Certification: ES000055

---
[ROTARTY_ENCODER]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/Rotary_encoder.webp
[ESP32 C3 Supermini]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/ESP32-C3.webp
[RPDZN5W6H]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/ac-dc_5V700mA.png
[CERN-OHL-W]: https://ohwr.org/cern_ohl_w_v2.pdf
[OSHWA]: https://certification.oshwa.org/list.html

