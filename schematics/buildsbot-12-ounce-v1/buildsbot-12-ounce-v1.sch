EESchema Schematic File Version 2  date Wed 14 Mar 2012 02:51:56 AM EDT
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
LIBS:special
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
LIBS:buildsbot-12-ounce
LIBS:atmega32u4bb-cache
LIBS:atmega32u4bb-from_eagle
LIBS:buildsbot-12-ounce-v1-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "14 mar 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2300 2250 2350 2250
Wire Wire Line
	2350 2250 2350 2350
Wire Wire Line
	2450 1025 2450 950 
Wire Wire Line
	2450 1500 1400 1500
Wire Wire Line
	2450 1500 2450 1425
Wire Wire Line
	1900 1250 1900 1550
Wire Wire Line
	1500 950  1325 950 
Wire Wire Line
	1825 1900 1825 2150
Wire Wire Line
	1825 2150 1600 2150
Wire Wire Line
	1600 2250 1900 2250
Wire Wire Line
	1850 2550 1900 2550
Wire Wire Line
	4625 2750 3100 2750
Wire Wire Line
	1850 2750 2600 2750
Connection ~ 4500 2150
Wire Wire Line
	4500 2150 4625 2150
Connection ~ 4500 2250
Wire Wire Line
	4500 2250 4625 2250
Wire Wire Line
	4625 2450 4500 2450
Wire Wire Line
	4500 2450 4500 1300
Connection ~ 4575 4450
Wire Wire Line
	4575 4450 4625 4450
Wire Wire Line
	4625 4150 4575 4150
Connection ~ 4225 3350
Wire Wire Line
	4625 3350 4150 3350
Wire Wire Line
	3750 3350 3675 3350
Wire Wire Line
	3675 3350 3675 4125
Wire Wire Line
	3750 4000 3675 4000
Connection ~ 3675 4000
Wire Wire Line
	4225 3950 4225 4000
Wire Wire Line
	4625 3650 4475 3650
Wire Wire Line
	4475 3650 4475 4000
Wire Wire Line
	4475 4000 4150 4000
Connection ~ 4225 4000
Wire Wire Line
	4575 4250 4625 4250
Connection ~ 4575 4250
Wire Wire Line
	4575 4350 4625 4350
Connection ~ 4575 4350
Wire Wire Line
	4625 3950 4575 3950
Wire Wire Line
	4575 3950 4575 4625
Connection ~ 4575 4150
Wire Wire Line
	4500 2350 4625 2350
Connection ~ 4500 2350
Wire Wire Line
	4500 2050 4625 2050
Connection ~ 4500 2050
Wire Wire Line
	2100 2650 1850 2650
Wire Wire Line
	2600 2650 4625 2650
Wire Wire Line
	1850 2950 2000 2950
Wire Wire Line
	2000 2950 2000 3100
Wire Wire Line
	4625 1750 4500 1750
Connection ~ 4500 1750
Wire Wire Line
	1900 2550 1900 2250
Wire Wire Line
	1175 1250 1175 1150
Wire Wire Line
	1400 1500 1400 1425
Connection ~ 1900 1500
Wire Wire Line
	1400 1025 1400 950 
Connection ~ 1400 950 
Wire Wire Line
	2300 950  2800 950 
Wire Wire Line
	2800 950  2800 2050
Wire Wire Line
	2800 2050 1600 2050
Connection ~ 2450 950 
$Comp
L GND #PWR?
U 1 1 4F603F52
P 2350 2350
F 0 "#PWR?" H 2350 2350 30  0001 C CNN
F 1 "GND" H 2350 2280 30  0001 C CNN
	1    2350 2350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F603F47
P 2100 2250
F 0 "C?" H 2150 2350 50  0000 L CNN
F 1 ".1 uF" H 2150 2150 50  0000 L CNN
	1    2100 2250
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 4F603EB7
P 2450 1225
F 0 "C?" H 2500 1325 50  0000 L CNN
F 1 ".1 uF" H 2500 1125 50  0000 L CNN
	1    2450 1225
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F603EB2
P 1400 1225
F 0 "C?" H 1450 1325 50  0000 L CNN
F 1 ".33 uF" H 1450 1125 50  0000 L CNN
	1    1400 1225
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F603E72
P 1900 1550
F 0 "#PWR?" H 1900 1550 30  0001 C CNN
F 1 "GND" H 1900 1480 30  0001 C CNN
	1    1900 1550
	1    0    0    -1  
$EndComp
$Comp
L LM7805 U?
U 1 1 4F603E63
P 1900 1000
F 0 "U?" H 2050 804 60  0000 C CNN
F 1 "LM7805" H 1900 1200 60  0000 C CNN
	1    1900 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F603DD8
P 1175 1250
F 0 "#PWR?" H 1175 1250 30  0001 C CNN
F 1 "GND" H 1175 1180 30  0001 C CNN
	1    1175 1250
	1    0    0    -1  
$EndComp
$Comp
L BNC P?
U 1 1 4F603DC2
P 1175 950
F 0 "P?" H 1185 1070 60  0000 C CNN
F 1 "BNC" V 1285 890 40  0000 C CNN
	1    1175 950 
	-1   0    0    -1  
$EndComp
Text Notes 2025 2150 0    60   ~ 0
(NOTE: use jumper to select if using \nUSB power or Battery/External power)\n
$Comp
L +5V #PWR?
U 1 1 4F603BCA
P 1825 1900
F 0 "#PWR?" H 1825 1990 20  0001 C CNN
F 1 "+5V" H 1825 1990 30  0000 C CNN
	1    1825 1900
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 J?
U 1 1 4F603B7A
P 1250 2150
F 0 "J?" H 1500 1875 50  0000 C CNN
F 1 "3 pin Header" H 1350 1950 40  0000 C CNN
	1    1250 2150
	-1   0    0    1   
$EndComp
NoConn ~ 1850 2850
$Comp
L GND #PWR?
U 1 1 4F60368A
P 2000 3100
F 0 "#PWR?" H 2000 3100 30  0001 C CNN
F 1 "GND" H 2000 3030 30  0001 C CNN
	1    2000 3100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4F603640
P 2850 2750
F 0 "R?" V 2930 2750 50  0000 C CNN
F 1 "22" V 2850 2750 50  0000 C CNN
	1    2850 2750
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 4F603635
P 2350 2650
F 0 "R?" V 2430 2650 50  0000 C CNN
F 1 "22" V 2350 2650 50  0000 C CNN
	1    2350 2650
	0    1    1    0   
$EndComp
$Comp
L ATMEGA32U4 U?
U 1 1 4F6035B6
P 4825 4550
F 0 "U?" H 5125 4250 60  0000 C CNN
F 1 "ATMEGA32U4" H 5325 4400 60  0000 C CNN
	1    4825 4550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 4F603433
P 4500 1300
F 0 "#PWR?" H 4500 1390 20  0001 C CNN
F 1 "+5V" H 4500 1390 30  0000 C CNN
	1    4500 1300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F603292
P 4575 4625
F 0 "#PWR?" H 4575 4625 30  0001 C CNN
F 1 "GND" H 4575 4555 30  0001 C CNN
	1    4575 4625
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F6031C6
P 3675 4125
F 0 "#PWR?" H 3675 4125 30  0001 C CNN
F 1 "GND" H 3675 4055 30  0001 C CNN
	1    3675 4125
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F6031BF
P 3950 4000
F 0 "C?" H 4000 4100 50  0000 L CNN
F 1 "10 pF" H 4000 3900 50  0000 L CNN
	1    3950 4000
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 4F6031B5
P 3950 3350
F 0 "C?" H 4000 3450 50  0000 L CNN
F 1 "10 pF" H 4000 3250 50  0000 L CNN
	1    3950 3350
	0    1    1    0   
$EndComp
$Comp
L CRYSTAL X?
U 1 1 4F6030DD
P 4225 3650
F 0 "X?" H 4225 3800 60  0000 C CNN
F 1 "16 MHz" H 4225 3500 60  0000 C CNN
	1    4225 3650
	0    -1   -1   0   
$EndComp
$Comp
L USB_MINIB J?
U 1 1 4F602FDE
P 1050 3050
F 0 "J?" H 1050 3690 50  0000 L BNN
F 1 "USB_MINIB" H 1050 2950 50  0000 L BNN
F 2 "USB-MINIB" H 1300 3100 50  0001 C CNN
	1    1050 3050
	1    0    0    -1  
$EndComp
$Comp
L AVR-ISP-6 J?
U 1 1 4F602EBE
P 2050 5425
F 0 "J?" H 1900 5675 50  0000 C CNN
F 1 "AVR-ISP-6" H 1800 5150 50  0000 L BNN
F 2 "AVR-ISP-6" V 1550 5425 50  0001 C CNN
	1    2050 5425
	1    0    0    -1  
$EndComp
$Comp
L SN754410 U?
U 1 1 4F602124
P 9300 3100
F 0 "U?" H 10250 3000 60  0000 C CNN
F 1 "SN754410" H 10450 3100 60  0000 C CNN
	1    9300 3100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
