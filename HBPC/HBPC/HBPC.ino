/*
 Name:		HBPC.ino
 Created:	14/05/2021 6:45:35 PM
 Author:	dmgci
*/

#include "utils.h"
#include "SN74HC595.h"
#include "AT28C256.h"

SN74HC595 sreg(A0, A1, A2, A3);

AT28C256 eeprom(&sreg, A4, PIN2);

#define x 0x100

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

void setup() 
{
	Serial.begin(9600);
	delay(1000);

	printf("Test\n");
	sreg.EnableOutput(true);
	Serial.println();
	test();
}

// the loop function runs over and over again until power down or reset
void loop() 
{

}
