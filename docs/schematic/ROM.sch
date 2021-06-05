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
L Memory_EEPROM:28C256 U1
U 1 1 60BA0C7A
P 4500 2550
F 0 "U1" H 4500 3831 50  0000 C CNN
F 1 "28C256" H 4500 3740 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm_Socket" H 4500 2550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc0006.pdf" H 4500 2550 50  0001 C CNN
	1    4500 2550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Counter_Clockwise J1
U 1 1 60BA5152
P 1600 2350
F 0 "J1" H 1650 3467 50  0000 C CNN
F 1 "Conn_02x20_Counter_Clockwise" H 1650 3376 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x20_P2.00mm_Vertical" H 1600 2350 50  0001 C CNN
F 3 "~" H 1600 2350 50  0001 C CNN
	1    1600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1450 1400 1000
Wire Wire Line
	1400 1000 4500 1000
Wire Wire Line
	4500 1000 4500 1450
Wire Wire Line
	1900 3350 1900 3800
Wire Wire Line
	1900 3800 4500 3800
Wire Wire Line
	4500 3800 4500 3650
Wire Wire Line
	1900 3250 2150 3250
Wire Wire Line
	2150 3250 2150 4000
Wire Wire Line
	2150 4000 5150 4000
Wire Wire Line
	5150 4000 5150 1850
Wire Wire Line
	5150 1850 4900 1850
Wire Wire Line
	1900 3150 2250 3150
Wire Wire Line
	2250 3150 2250 4100
Wire Wire Line
	2250 4100 5250 4100
Wire Wire Line
	5250 4100 5250 1750
Wire Wire Line
	5250 1750 4900 1750
Wire Wire Line
	1900 3050 2350 3050
Wire Wire Line
	2350 3050 2350 4200
Wire Wire Line
	2350 4200 5400 4200
Wire Wire Line
	5400 4200 5400 1650
Wire Wire Line
	5400 1650 4900 1650
Wire Wire Line
	1900 2950 2300 2950
Wire Wire Line
	2300 2950 2300 1650
Wire Wire Line
	2300 1650 4100 1650
Wire Wire Line
	1900 2850 2400 2850
Wire Wire Line
	2400 2850 2400 1750
Wire Wire Line
	2400 1750 4100 1750
Wire Wire Line
	1900 2750 2500 2750
Wire Wire Line
	2500 2750 2500 1850
Wire Wire Line
	2500 1850 4100 1850
Wire Wire Line
	1900 2650 2600 2650
Wire Wire Line
	2600 2650 2600 1950
Wire Wire Line
	2600 1950 4100 1950
Wire Wire Line
	1900 2550 2700 2550
Wire Wire Line
	2700 2550 2700 2050
Wire Wire Line
	2700 2050 4100 2050
Wire Wire Line
	1900 2450 2800 2450
Wire Wire Line
	2800 2450 2800 2150
Wire Wire Line
	2800 2150 4100 2150
Wire Wire Line
	2900 2350 2900 2250
Wire Wire Line
	2900 2250 4100 2250
Wire Wire Line
	1900 2350 2900 2350
Wire Wire Line
	1900 2250 2850 2250
Wire Wire Line
	2850 2250 2850 2300
Wire Wire Line
	2850 2300 2950 2300
Wire Wire Line
	2950 2300 2950 2350
Wire Wire Line
	2950 2350 4100 2350
Wire Wire Line
	1900 2150 2750 2150
Wire Wire Line
	2750 2150 2750 2400
Wire Wire Line
	2750 2400 4100 2400
Wire Wire Line
	4100 2400 4100 2450
$EndSCHEMATC
