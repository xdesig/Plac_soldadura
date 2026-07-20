
> [!NOTE]
> Documentaci&oacute;n en galego

Este repositorio cont&eacute;n o dese&ntilde;o de hardware, esquema e firmware para o desenvolvemento dun **controlador t&eacute;rmico intelixente** aplicado a unha placa calefactora de 230Vac. O sistema est&aacute; dese&ntilde;ado para labores de soldadura e desoldadura de compo&ntilde;entes SMD/THD en proxectos persoais, educativos e experimentais.

---

## ?? Versi&oacute;ns do Proxecto

O repositorio est&aacute; dividido en d&uacute;as variantes segundo o microcontrolador utilizado:

### 1. ?? [Plataforma_sold_ATmega328p](./Plataforma_sold_ATmega328p)
- **Microcontrolador:** ATmega328P-AU (TQFP-32)
- **Descrici&oacute;n:** Versi&oacute;n m&aacute;is lixeira e eficiente baseada na arquitectura cl&aacute;sica de Arduino. Demostra que non &eacute; necesario un microprocesador de alta potencia para un control t&eacute;rmico preciso e estable.
- **Caracter&iacute;sticas:** Control de potencia, visualizaci&oacute;n en pantalla OLED 128x64 (SSD1306) e illamento galv&aacute;nico.

?? **[Ver documentaci&oacute;n e BOM do ATmega328P](./Plataforma_sold_ATmega328p)**

---

### 2. ? [Plataforma_sold_ESP32-C3](./Plataforma_sold_ESP32-C3)
- **Microcontrolador:** ESP32-C3 SuperMini (RISC-V)
- **Descrici&oacute;n:** Versi&oacute;n baseada no chip ESP32-C3, aproveitando a s&uacute;a maior velocidade de procesamento e futuras capacidades de conectividade sen f&iacute;os.
- **Caracter&iacute;sticas:** Interface OLED I2C, control mediante encoder rotatorio e procesamento m&aacute;is r&aacute;pido da curva de temperatura.

?? **[Ver documentaci&oacute;n e BOM do ESP32-C3](./Plataforma_sold_ESP32-C3)**

---

## ? Caracter&iacute;sticas Xerais

Ambas versi&oacute;ns comparten a seguinte arquitectura e funcionalidade b&aacute;sica:

- **Control T&eacute;rmico:** Axuste preciso da temperatura e control de potencia do elemento calefactor.
- **Seguridade:** Detecci&oacute;n de fallos no termistor e corte de emerxencia por sobrequecemento (300&deg;C).
- **Aisllamento:** Illamento galv&aacute;nico mediante micro-fonte de alimentaci&oacute;n conmutada integrada na PCB.
- **Etapa de Potencia:** Control de carga AC a 230Vac mediante SSR / Triac (BTA06-400B e optoacoplador MOC3041).
- **Interface:** Pantalla OLED SSD1306 (128x64 px) e selector mediante encoder rotatorio e pulsador.

---

## ?? Estrutura do Repositorio

```text
Plac_soldadura/
+-- Plataforma_sold_ATmega328p/   # Proxecto, PCB e BOM para ATmega328P
+-- Plataforma_sold_ESP32-C3/      # Proxecto, PCB e BOM para ESP32-C3
+-- README.md                      # Descrici&oacute;n xeral do repositorio