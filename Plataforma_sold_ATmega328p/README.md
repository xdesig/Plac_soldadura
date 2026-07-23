# Controlador de placa para soldar Con ATmega328p
<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Plataforma_sold_ATmega328p/Imaxes/IMG_20260528_120601.jpg" width="300" align="right">

> [!NOTE]
> Documentation in Galego 
> [traductor](https://tradutorgaio.xunta.gal/TradutorPublico/traducir/index)

Tr&aacute;tase dun **controlador t&eacute;rmico intelixente** de placa calefactora 230Vac para soldar/desoldar, dese&ntilde;ado para uso persoal, educativo e experimental. Baseado en ATmega328, non &eacute; preciso usar un potente ESP32 para realizar este traballo, e permite:

- Axuste preciso da temperatura (ata 300&deg;C).
- Control "PID" simple e estable.
- Detecci&oacute;n de fallos do termistor.
- Gr&aacute;fico en tempo real da temperatura.
- Indicador ON/OFF e potencia aplicada ao calefactor na pantalla.
- Corte de emerxencia por sobrequecemento (300&deg;C).
- Illamento galv&aacute;nico (micro-fonte de alimentaci&oacute;n conmutada).
- Control mediante SSR (Triac) a 230Vac.
 <img src="https://github.com/xdesig/Plac_soldadura/blob/main/Plataforma_sold_ATmega328p/Imaxes/IMG_20260521_140713.jpg" width="300" align="left">

Sa&uacute;dos.

## [Versi&oacute;n 00]


## Listado de Compoñentes (BOM)

|Cant | Valor        | Dispositivo                       | Parte            | Descrición         |
|-----|--------------|-----------------------------------|------------------|------------------|
| **1** | 100R | R0603 | `R1` | Resistor |
| **1** | 100nF | C0603 | `C3` | Capacitor |
| **3** | 10K | R0603 | `R6`, `R8`, `R9` | Resistor |
| **1** | 10nF / 400V | C075-042X103 | `C1` | Capacitor (400V) |
| **1** | 10uF | C1206 | `C2` | Capacitor |
| **1** | 1K | R0603 | `R7` | Resistor |
| **1** | 1uF | C0603 | `C4` | Capacitor |
| **4** | 200R | R1206 | `R2`, `R3`, `R12`, `R13` | Resistor |
| **1** | 22-05-7028-02 | 7395-02 | `J1` | Connector |
| **1** | 39R | 0204/7 | `R4` | Resistor |
| **1** | 47K | R0603 | `R5` | Resistor |
| **2** | 4K7 | R0603 | `R10`, `R11` | Resistor |
| **1** | ATMEGA328P-AU | TQFP-32 | `IC3` | 8-bit Microcontrolador 32KB Flash |
| **1** | B3U-1000P | SMD_157SW | `S6` | Pulsador 4x3mm SMD H2.5mm |
| **1** | BTA06-400B (BT136) | TO-220AB | `T1` | Triac  |
| **1** | CSTCE16M0V53C-R0 | Resonador | `Y1` | Resonador 16MHz SMD |
| **1** | OLED 0.96" I2C | 128x64 Modulo | `OL1` | SSD1306 [GND, VCC, SCL, SDA] |
| **1** | Fusible| TE5 | `F1` | Fusible |
| **1** | MOC3041 | DIL06 / DIP-6 | `OK1` | Optoacoplador, Triac |
| **1** | Rotary Encoder | Rotary Enc Plain | `SW2` | Encoder rotativo pulsador |
| **1** | RPDZN5W6H | Module | `U1` | Modulo Micro fuente A. |



## Deseñado en Estrimia con agarimo.

### Author and license
* Author: XDeSIG [No Twitter, no X]
* License: [CERN Open Hardware Licence Version 2 - S - Reciprocal][CERN-OHL-W]
* Open Hardware Certification: ES000057 

<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Plataforma_sold_ATmega328p/Imaxes/ES000057.svg" width="100" align="left">


---
[ROTARTY_ENCODER]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/Rotary_encoder.webp
[RPDZN5W6H]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/ac-dc_5V700mA.png
[CERN-OHL-W]: https://ohwr.org/cern_ohl_w_v2.pdf
[OSHWA]: https://certification.oshwa.org/list.html

