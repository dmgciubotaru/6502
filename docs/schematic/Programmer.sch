EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 60B0FD1B
P 6300 2300
F 0 "A1" H 6300 1211 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 6300 1120 50  0000 C TNN
F 2 "Module:Arduino_Nano" H 6300 2300 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 6300 2300 50  0001 C CNN
	1    6300 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x40_Male J1
U 1 1 60B13E9E
P 1550 3300
F 0 "J1" H 1658 5381 50  0000 C CNN
F 1 "Conn_01x40_Male" H 1658 5290 50  0000 C CNN
F 2 "" H 1550 3300 50  0001 C CNN
F 3 "~" H 1550 3300 50  0001 C CNN
	1    1550 3300
	1    0    0    -1  
$EndComp
Text Label 1550 1400 2    50   ~ 0
A15
Text Label 1550 1500 2    50   ~ 0
A14
Text Label 1550 1600 2    50   ~ 0
A13
Text Label 1550 1700 2    50   ~ 0
A12
Text Label 1550 1800 2    50   ~ 0
A11
Text Label 1550 1900 2    50   ~ 0
A10
Text Label 1550 2000 2    50   ~ 0
A9
Text Label 1550 2100 2    50   ~ 0
A8
Text Label 1550 2200 2    50   ~ 0
A7
Text Label 1550 2300 2    50   ~ 0
A6
Text Label 1550 2400 2    50   ~ 0
A5
Text Label 1550 2500 2    50   ~ 0
A4
Text Label 1550 2600 2    50   ~ 0
A3
Text Label 1550 2700 2    50   ~ 0
A2
Text Label 1550 2800 2    50   ~ 0
A1
Text Label 1550 3900 2    50   ~ 0
RW
Text Label 1550 4000 2    50   ~ 0
RSTn
Text Label 1550 4100 2    50   ~ 0
IRQn
Text Label 1550 4200 2    50   ~ 0
NMIn
Text Label 1550 4300 2    50   ~ 0
CLK
Text Label 1550 4400 2    50   ~ 0
RDY
Text Label 1550 4500 2    50   ~ 0
SYNC
Text Label 1550 4600 2    50   ~ 0
BRK
Text Label 1550 4700 2    50   ~ 0
BE
Text Label 1550 5300 2    50   ~ 0
VCC
Entry Wire Line
	6800 2300 6900 2400
Entry Wire Line
	6800 2400 6900 2500
Entry Wire Line
	6800 2500 6900 2600
Entry Wire Line
	6800 2600 6900 2700
Entry Wire Line
	6800 2700 6900 2800
Entry Wire Line
	6800 2800 6900 2900
Entry Wire Line
	6800 2900 6900 3000
Entry Wire Line
	6800 3000 6900 3100
Text Label 1550 3800 2    50   ~ 0
D7
Text Label 1550 3700 2    50   ~ 0
D6
Text Label 1550 3600 2    50   ~ 0
D5
Text Label 1550 3500 2    50   ~ 0
D4
Text Label 1550 3400 2    50   ~ 0
D3
Text Label 1550 3300 2    50   ~ 0
GND
Text Label 1550 3200 2    50   ~ 0
D2
Text Label 1550 3100 2    50   ~ 0
D1
Text Label 1550 3000 2    50   ~ 0
D0
Text Label 1550 2900 2    50   ~ 0
A0
Entry Wire Line
	1750 3000 1850 3100
Entry Wire Line
	1750 3100 1850 3200
Entry Wire Line
	1750 3200 1850 3300
Entry Wire Line
	1750 3400 1850 3500
Entry Wire Line
	1750 3500 1850 3600
Entry Wire Line
	1750 3600 1850 3700
Entry Wire Line
	1750 3700 1850 3800
Entry Wire Line
	1750 3800 1850 3900
$Comp
L power:GND #PWR?
U 1 1 60B4196F
P 2000 3300
F 0 "#PWR?" H 2000 3050 50  0001 C CNN
F 1 "GND" H 2005 3127 50  0000 C CNN
F 2 "" H 2000 3300 50  0001 C CNN
F 3 "" H 2000 3300 50  0001 C CNN
	1    2000 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60B4749D
P 6400 3300
F 0 "#PWR?" H 6400 3050 50  0001 C CNN
F 1 "GND" H 6405 3127 50  0000 C CNN
F 2 "" H 6400 3300 50  0001 C CNN
F 3 "" H 6400 3300 50  0001 C CNN
	1    6400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3300 6400 3300
Connection ~ 6400 3300
$Comp
L 74xx:74HC595 U?
U 1 1 60B4B087
P 2800 1800
F 0 "U?" H 2800 2581 50  0000 C CNN
F 1 "74HC595" H 2800 2490 50  0000 C CNN
F 2 "" H 2800 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2800 1800 50  0001 C CNN
	1    2800 1800
	-1   0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 60B4CE39
P 2800 3200
F 0 "U?" H 2800 3981 50  0000 C CNN
F 1 "74HC595" H 2800 3890 50  0000 C CNN
F 2 "" H 2800 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2800 3200 50  0001 C CNN
	1    2800 3200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1750 1400 2400 1400
Wire Wire Line
	1750 1500 2400 1500
Wire Wire Line
	1750 1600 2400 1600
Wire Wire Line
	1750 1700 2400 1700
Wire Wire Line
	1750 1800 2400 1800
Wire Wire Line
	2400 1900 1750 1900
Wire Wire Line
	1750 2000 2400 2000
Wire Wire Line
	2400 2100 1750 2100
Wire Wire Line
	2400 2800 2200 2800
Wire Wire Line
	2200 2800 2200 2200
Wire Wire Line
	2200 2200 1750 2200
Wire Wire Line
	2400 2900 2150 2900
Wire Wire Line
	2150 2900 2150 2300
Wire Wire Line
	2150 2300 1750 2300
Wire Wire Line
	1750 3300 2000 3300
Wire Bus Line
	1850 3100 1850 4000
Wire Bus Line
	6900 2400 6900 3950
$EndSCHEMATC
