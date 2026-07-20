<img src="https://github.com/xdesig/Plac_soldadura/blob/main/Plataforma_sold_ESP32-C3/Imaxes/IMG_20260528_120601.jpg" width="300" align="right">

> [!NOTE]
> Documentaci&oacute;n en galego

Tr&aacute;tase dun **controlador t&eacute;rmico intelixente** de placa calefactora 230Vac para soldar/desoldar, dese&ntilde;ado para uso persoal, educativo e experimental. Esta versi&oacute;n est&aacute; basada no microcontrolador **ESP32-C3 SuperMini**, aproveitando a s&uacute;a alta velocidade e conectividade para a xesti&oacute;n de temperatura e control de potencia.

### Caracter&iacute;sticas principais:
- Axuste preciso da temperatura.
- Control de potencia e ciclo de quecemento.
- Detecci&oacute;n de fallos do sensor de temperatura.
- Visualizaci&oacute;n en pantalla OLED (SSD1306 / I2C).
- Corte de emerxencia por sobrequecemento.
- Illamento galv&aacute;nico (micro-fonte de alimentaci&oacute;n conmutada).
- Control de carga AC mediante triac / SSR.

---

## ?? Bill of Materials (BOM)

| Qty | Value / Component | Footprint / Package | Designator | Description |
| :---: | :--- | :--- | :--- | :--- |
| **1** | ESP32-C3 SuperMini | Module / Board | `U1` | ESP32-C3 Microcontrolador modulo |
| **1** | OLED 0.96" I2C | 128x64 Module | `OL1` |  (SSD1306) |
| **1** | BTA06-400B (BT136) | TO-220AB | `T1` | Triac  |
| **1** | MOC3041 | DIL06 / DIP-6 | `OK1` | Optocoupler Triac Driver |
| **1** | Rotary Encoder | Rotary Enc Plain | `SW2` | Rotary Encoder (No LED) |
| **1** | Pushbutton | SMD / DIP | `S6` | Tactile Switch Button |
| **1** | Fuse | TE5 / Holder | `F1` | Fuse |
| **1** | Power Supply | Module | `PS1` | Micro Power Supply Module 230VAC to DC |
| **1** | 100R | R0603 / R1206 | `R1` | Resistor |
| **1** | 100nF | C0603 | `C3` | Capacitor |
| **3** | 10K | R0603 | `R6`, `R8`, `R9` | Resistor |
| **1** | 10nF / 400V | C075-042X103 | `C1` | Capacitor (400V) |
| **1** | 10uF | C1206 | `C2` | Capacitor |
| **1** | 1K | R0603 | `R7` | Resistor |
| **1** | 1uF | C0603 | `C4` | Capacitor |
| **4** | 200R | R1206 | `R2`, `R3`, `R12`, `R13` | Resistor |
| **1** | 39R | 0204/7 | `R4` | Resistor |
| **1** | 47K | R0603 | `R5` | Resistor |
| **2** | 4K7 | R0603 | `R10`, `R11` | Resistor |
| **3** | 3.0mm | Mounting Hole | `H1`, `H3`, `H4` | Mounting Hole |

---

Sa&uacute;dos.

## [Versi&oacute;n ESP32-C3]
---
[ROTARTY_ENCODER]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/Rotary_encoder.webp
[ESP32 C3 Supermini]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/ESP32-C3.webp
[RPDZN5W6H]: https://github.com/xdesig/Plac_soldadura/blob/main/Imaxes/ac-dc_5V700mA.png
[CERN-OHL-W]: https://ohwr.org/cern_ohl_w_v2.pdf
[OSHWA]: https://certification.oshwa.org/list.html

