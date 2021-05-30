/*
 Name:		HBPC.ino
 Created:	14/05/2021 6:45:35 PM
 Author:	dmgci
*/

#include "utils.h"
#include "SN74HC595.h"
#include "AT28C256.h"
#include "..\common\HBDefs.h"
#include <simpletimer.h>


SN74HC595 sreg(A0, A1, A2, A3);

AT28C256 eeprom(&sreg, A4, PIN2);

#define x 0x100

SimpleTimer timer;



void write_buff(uint8_t* data, uint16_t size, uint16_t addr)
{

	int errs[100];
	int errcnt = 0;

	for (uint16_t i = 0; i < size; i++)
	{
		eeprom.Write(addr + i, data[i]);
	}

	for (uint16_t i = 0; i < size; i++)
	{
		if (eeprom.Read(addr + i) != data[i])
		{
			errs[errcnt++] = i + addr;
		}
	}

	printf("%d errors\n", errcnt);
	for (int i = 0; i < errcnt; i++)
	{
		printf("Error on 0x%04x\n", errs[i]);
	}
}

void prg_dump()
{
	printf("Programming\n");
	uint8_t rst[] = { 0x00, 0x80, 0x00, 0x80, 0x00, 0x80};
	write_buff(rst, 6, 0xFFFA);
	
	uint8_t prg[] = { 0x4c, 0x00, 0x80 };
	write_buff(prg, 3, 0x8000);
}

void test()
{
	int errs[100];
	int errcnt = 0;

	for (int16_t i = 0; i < x; i++)
	{
		eeprom.Write(0xfe00 + i, i);
	}

	for (int16_t i = 0; i < x; i++)
	{
		if (eeprom.Read(0xFe00 + i) != i)
		{
			errs[errcnt++] = i + 0xFe00;
		}
	}
	printf("%d errors\n", errcnt);
	for (int i = 0; i < errcnt; i++)
	{
		printf("Error on 0x%04x\n", errs[i]);
	}
}

void clock()
{
	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setup() 
{
	Serial.begin(9600);
	delay(1000);

	//sreg.EnableOutput(true);
	Serial.println();
	//prg_dump();
	//test();
	timer.setInterval(1000);
	pinMode(LED_BUILTIN, OUTPUT);
}



// the loop function runs over and over again until power down or reset
void loop() 
{
	if (timer.isReady())
	{
		clock();
		timer.reset();
	}
	//Serial.print("OK\n");
	
}

void serialEvent() 
{
	while (Serial.available())
	{
		
		char inChar = (char)Serial.read();
		switch (inChar)
		{
			case (char)HBCCmd::PING:
			{
				printf("pong\n");
			};
		default:
			break;
		}
	}
}
