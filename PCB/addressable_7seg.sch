EESchema Schematic File Version 4
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:AP2112k
LIBS:addressable_7seg-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "TEMPLATE FILE"
Date "2018-08-14"
Rev "0.1p"
Comp "Idle Hands Dev."
Comment1 "Sean Hodgins"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_LED:WS2811 U2
U 1 1 5BDA1669
P 7650 4200
F 0 "U2" H 7400 4450 50  0000 C CNN
F 1 "WS2811" H 7850 4450 50  0000 C CNN
F 2 "Package_SO:SSOP-8_3.95x5.21x3.27mm_P1.27mm" H 7350 4350 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2811.pdf" H 7450 4450 50  0001 C CNN
	1    7650 4200
	1    0    0    -1  
$EndComp
$Comp
L Driver_LED:WS2811 U1
U 1 1 5BDA16D9
P 7650 3150
F 0 "U1" H 7650 3628 50  0000 C CNN
F 1 "WS2811" H 7650 3537 50  0000 C CNN
F 2 "Package_SO:SSOP-8_3.95x5.21x3.27mm_P1.27mm" H 7350 3300 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2811.pdf" H 7450 3400 50  0001 C CNN
	1    7650 3150
	1    0    0    -1  
$EndComp
$Comp
L Driver_LED:WS2811 U3
U 1 1 5BDA1745
P 7650 5200
F 0 "U3" H 7400 5450 50  0000 C CNN
F 1 "WS2811" H 7850 5450 50  0000 C CNN
F 2 "Package_SO:SSOP-8_3.95x5.21x3.27mm_P1.27mm" H 7350 5350 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2811.pdf" H 7450 5450 50  0001 C CNN
	1    7650 5200
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:KCSA02-107 U4
U 1 1 5BDA18C7
P 10700 3850
F 0 "U4" H 10700 4517 50  0000 C CNN
F 1 "KCSA02-107" H 10700 4426 50  0000 C CNN
F 2 "project_footprints:YSD-160AR4B-8" H 10700 3250 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/KCSA02-107(Ver.10A).pdf" H 10200 4325 50  0001 L CNN
	1    10700 3850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 5BDA1BE9
P 11150 4050
F 0 "#PWR0101" H 11150 3900 50  0001 C CNN
F 1 "VCC" H 11167 4223 50  0000 C CNN
F 2 "" H 11150 4050 50  0001 C CNN
F 3 "" H 11150 4050 50  0001 C CNN
	1    11150 4050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5BDA1C19
P 6800 2650
F 0 "#PWR0102" H 6800 2500 50  0001 C CNN
F 1 "VCC" H 6817 2823 50  0000 C CNN
F 2 "" H 6800 2650 50  0001 C CNN
F 3 "" H 6800 2650 50  0001 C CNN
	1    6800 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4100 8050 4100
Wire Wire Line
	8200 4200 8050 4200
Wire Wire Line
	8050 4300 8200 4300
Wire Wire Line
	8050 5100 8200 5100
Wire Wire Line
	8050 5200 8200 5200
Wire Wire Line
	11000 4150 11150 4150
Wire Wire Line
	11150 4150 11150 4050
Wire Wire Line
	11000 4250 11150 4250
Wire Wire Line
	11150 4250 11150 4150
Connection ~ 11150 4150
$Comp
L Device:LED D1
U 1 1 5BDA2F8B
P 9100 5300
F 0 "D1" H 9091 5516 50  0000 C CNN
F 1 "LED" H 9091 5425 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9100 5300 50  0001 C CNN
F 3 "~" H 9100 5300 50  0001 C CNN
	1    9100 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5300 8950 5300
$Comp
L power:VCC #PWR0103
U 1 1 5BDA37BC
P 9350 5250
F 0 "#PWR0103" H 9350 5100 50  0001 C CNN
F 1 "VCC" H 9367 5423 50  0000 C CNN
F 2 "" H 9350 5250 50  0001 C CNN
F 3 "" H 9350 5250 50  0001 C CNN
	1    9350 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 5300 9350 5300
Wire Wire Line
	9350 5300 9350 5250
Wire Wire Line
	6800 2650 6800 2850
Wire Wire Line
	6800 4900 7650 4900
Wire Wire Line
	7650 3900 6800 3900
Connection ~ 6800 3900
Wire Wire Line
	6800 3900 6800 4900
Wire Wire Line
	7650 2850 6800 2850
Connection ~ 6800 2850
Wire Wire Line
	6800 2850 6800 3900
$Comp
L Device:R_Small R3
U 1 1 5BDA4D19
P 7000 4600
F 0 "R3" H 7059 4646 50  0000 L CNN
F 1 "33R" H 7059 4555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 7000 4600 50  0001 C CNN
F 3 "~" H 7000 4600 50  0001 C CNN
	1    7000 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 5BDA4DA8
P 7000 3650
F 0 "R2" H 7059 3696 50  0000 L CNN
F 1 "33R" H 7059 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 7000 3650 50  0001 C CNN
F 3 "~" H 7000 3650 50  0001 C CNN
	1    7000 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5BDA4E63
P 6450 3050
F 0 "R1" V 6254 3050 50  0000 C CNN
F 1 "33R" V 6345 3050 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 6450 3050 50  0001 C CNN
F 3 "~" H 6450 3050 50  0001 C CNN
	1    6450 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 3050 7250 3050
Wire Wire Line
	7250 3150 7000 3150
Wire Wire Line
	7000 3150 7000 3550
Wire Wire Line
	7000 3750 7000 4100
Wire Wire Line
	7000 4100 7250 4100
Wire Wire Line
	7250 4200 7000 4200
Wire Wire Line
	7000 4200 7000 4500
Wire Wire Line
	7000 4700 7000 5100
Wire Wire Line
	7000 5100 7250 5100
Wire Wire Line
	7250 5200 7000 5200
Wire Wire Line
	7000 5200 7000 5650
Text GLabel 7650 6400 0    60   Input ~ 0
OUT
Text GLabel 7000 5650 0    60   Input ~ 0
OUT
Text GLabel 9250 6400 2    60   Input ~ 0
IN
$Comp
L power:VCC #PWR0104
U 1 1 5BDA8CFA
P 9350 6250
F 0 "#PWR0104" H 9350 6100 50  0001 C CNN
F 1 "VCC" H 9367 6423 50  0000 C CNN
F 2 "" H 9350 6250 50  0001 C CNN
F 3 "" H 9350 6250 50  0001 C CNN
	1    9350 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5BDA8D3E
P 7650 5600
F 0 "#PWR0105" H 7650 5350 50  0001 C CNN
F 1 "GND" H 7655 5427 50  0000 C CNN
F 2 "" H 7650 5600 50  0001 C CNN
F 3 "" H 7650 5600 50  0001 C CNN
	1    7650 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5BDA8D64
P 7650 4600
F 0 "#PWR0106" H 7650 4350 50  0001 C CNN
F 1 "GND" H 7655 4427 50  0000 C CNN
F 2 "" H 7650 4600 50  0001 C CNN
F 3 "" H 7650 4600 50  0001 C CNN
	1    7650 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5BDA8E73
P 7650 3550
F 0 "#PWR0107" H 7650 3300 50  0001 C CNN
F 1 "GND" H 7655 3377 50  0000 C CNN
F 2 "" H 7650 3550 50  0001 C CNN
F 3 "" H 7650 3550 50  0001 C CNN
	1    7650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3550 7650 3450
Wire Wire Line
	7650 4600 7650 4500
Wire Wire Line
	7650 5600 7650 5500
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 5BDAB39A
P 5000 6350
F 0 "JP1" H 5000 6562 50  0000 C CNN
F 1 "Jumper_NC_Small" H 5000 6471 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5000 6350 50  0001 C CNN
F 3 "~" H 5000 6350 50  0001 C CNN
	1    5000 6350
	1    0    0    -1  
$EndComp
Text GLabel 6350 3050 0    60   Input ~ 0
IN
$Comp
L power:VCC #PWR0108
U 1 1 5BDAC270
P 7550 6250
F 0 "#PWR0108" H 7550 6100 50  0001 C CNN
F 1 "VCC" H 7567 6423 50  0000 C CNN
F 2 "" H 7550 6250 50  0001 C CNN
F 3 "" H 7550 6250 50  0001 C CNN
	1    7550 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5BDAC291
P 7550 6650
F 0 "#PWR0109" H 7550 6400 50  0001 C CNN
F 1 "GND" H 7555 6477 50  0000 C CNN
F 2 "" H 7550 6650 50  0001 C CNN
F 3 "" H 7550 6650 50  0001 C CNN
	1    7550 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5BDAC2B2
P 9350 6650
F 0 "#PWR0110" H 9350 6400 50  0001 C CNN
F 1 "GND" H 9355 6477 50  0000 C CNN
F 2 "" H 9350 6650 50  0001 C CNN
F 3 "" H 9350 6650 50  0001 C CNN
	1    9350 6650
	1    0    0    -1  
$EndComp
Text GLabel 7250 5300 0    60   Input ~ 0
SET
Text GLabel 7250 4300 0    60   Input ~ 0
SET
Text GLabel 7250 3250 0    60   Input ~ 0
SET
Text GLabel 5250 6350 2    60   Input ~ 0
SET
$Comp
L power:VCC #PWR0111
U 1 1 5BDAC38A
P 4550 6250
F 0 "#PWR0111" H 4550 6100 50  0001 C CNN
F 1 "VCC" H 4567 6423 50  0000 C CNN
F 2 "" H 4550 6250 50  0001 C CNN
F 3 "" H 4550 6250 50  0001 C CNN
	1    4550 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 6250 4550 6350
Wire Wire Line
	4550 6350 4900 6350
Wire Wire Line
	5100 6350 5250 6350
Wire Wire Line
	7550 6250 7550 6300
Wire Wire Line
	7550 6300 7650 6300
Wire Wire Line
	7550 6650 7550 6500
Wire Wire Line
	7550 6500 7650 6500
Wire Wire Line
	9250 6500 9350 6500
Wire Wire Line
	9350 6500 9350 6650
Wire Wire Line
	9250 6300 9350 6300
Wire Wire Line
	9350 6300 9350 6250
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5BDB38A8
P 7850 6400
F 0 "J1" H 7930 6442 50  0000 L CNN
F 1 "OUT" H 7930 6351 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Horizontal" H 7850 6400 50  0001 C CNN
F 3 "~" H 7850 6400 50  0001 C CNN
	1    7850 6400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5BDB5CF2
P 9050 6400
F 0 "J2" H 8970 6717 50  0000 C CNN
F 1 "IN" H 8970 6626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 9050 6400 50  0001 C CNN
F 3 "~" H 9050 6400 50  0001 C CNN
	1    9050 6400
	-1   0    0    -1  
$EndComp
Text GLabel 8150 3250 2    60   Input ~ 0
B
Text GLabel 8150 3150 2    60   Input ~ 0
A
Text GLabel 8150 3050 2    60   Input ~ 0
F
Wire Wire Line
	8050 3050 8150 3050
Wire Wire Line
	8050 3150 8150 3150
Wire Wire Line
	8050 3250 8150 3250
Text GLabel 10400 3650 0    60   Input ~ 0
B
Text GLabel 10400 3550 0    60   Input ~ 0
A
Text GLabel 10400 4050 0    60   Input ~ 0
F
Text GLabel 10400 3750 0    60   Input ~ 0
C
Text GLabel 10400 3850 0    60   Input ~ 0
D
Text GLabel 10400 3950 0    60   Input ~ 0
E
Text GLabel 10400 4150 0    60   Input ~ 0
G
Text GLabel 10400 4250 0    60   Input ~ 0
DP
Text GLabel 8200 4100 2    60   Input ~ 0
DP
Text GLabel 8200 4200 2    60   Input ~ 0
C
Text GLabel 8200 4300 2    60   Input ~ 0
D
Text GLabel 8200 5100 2    60   Input ~ 0
G
Text GLabel 8200 5200 2    60   Input ~ 0
E
$Comp
L Device:C_Small C1
U 1 1 5BDBE3DB
P 8650 3050
F 0 "C1" H 8742 3096 50  0000 L CNN
F 1 "1uF" H 8742 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8650 3050 50  0001 C CNN
F 3 "~" H 8650 3050 50  0001 C CNN
	1    8650 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5BDBE4D7
P 9050 3050
F 0 "C2" H 9142 3096 50  0000 L CNN
F 1 "1uF" H 9142 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9050 3050 50  0001 C CNN
F 3 "~" H 9050 3050 50  0001 C CNN
	1    9050 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5BDBE523
P 9400 3050
F 0 "C3" H 9492 3096 50  0000 L CNN
F 1 "1uF" H 9492 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9400 3050 50  0001 C CNN
F 3 "~" H 9400 3050 50  0001 C CNN
	1    9400 3050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5BDBE563
P 8650 2900
F 0 "#PWR0112" H 8650 2750 50  0001 C CNN
F 1 "VCC" H 8667 3073 50  0000 C CNN
F 2 "" H 8650 2900 50  0001 C CNN
F 3 "" H 8650 2900 50  0001 C CNN
	1    8650 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5BDBE58A
P 8650 3200
F 0 "#PWR0113" H 8650 2950 50  0001 C CNN
F 1 "GND" H 8655 3027 50  0000 C CNN
F 2 "" H 8650 3200 50  0001 C CNN
F 3 "" H 8650 3200 50  0001 C CNN
	1    8650 3200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0114
U 1 1 5BDBE5B1
P 9050 2900
F 0 "#PWR0114" H 9050 2750 50  0001 C CNN
F 1 "VCC" H 9067 3073 50  0000 C CNN
F 2 "" H 9050 2900 50  0001 C CNN
F 3 "" H 9050 2900 50  0001 C CNN
	1    9050 2900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 5BDBE5D8
P 9400 2900
F 0 "#PWR0115" H 9400 2750 50  0001 C CNN
F 1 "VCC" H 9417 3073 50  0000 C CNN
F 2 "" H 9400 2900 50  0001 C CNN
F 3 "" H 9400 2900 50  0001 C CNN
	1    9400 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5BDBE5FF
P 9050 3200
F 0 "#PWR0116" H 9050 2950 50  0001 C CNN
F 1 "GND" H 9055 3027 50  0000 C CNN
F 2 "" H 9050 3200 50  0001 C CNN
F 3 "" H 9050 3200 50  0001 C CNN
	1    9050 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5BDBE626
P 9400 3200
F 0 "#PWR0117" H 9400 2950 50  0001 C CNN
F 1 "GND" H 9405 3027 50  0000 C CNN
F 2 "" H 9400 3200 50  0001 C CNN
F 3 "" H 9400 3200 50  0001 C CNN
	1    9400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 2950 8650 2900
Wire Wire Line
	8650 3200 8650 3150
Wire Wire Line
	9050 2950 9050 2900
Wire Wire Line
	9050 3200 9050 3150
Wire Wire Line
	9400 2950 9400 2900
Wire Wire Line
	9400 3200 9400 3150
$EndSCHEMATC
