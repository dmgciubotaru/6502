#include "eeprom_lib.h"

EEPROM::EEPROM()
{
	pinMode(EEPROM_DATA1, OUTPUT);
	pinMode(EEPROM_DATA2, OUTPUT);
	pinMode(EEPROM_CLK, OUTPUT);
	pinMode(EEPROM_CEN, OUTPUT);
	pinMode(EEPROM_WEN, OUTPUT);
	pinMode(EEPROM_OEN, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);
	ResetLines();
}

uint8_t EEPROM::Read(uint16_t address)
{
	SetDataMode(INPUT);
	SetAddress(address);
	digitalWrite(EEPROM_CEN, LOW);
	digitalWrite(EEPROM_OEN, LOW);
	delay(1000);
	uint8_t data = GetData();
	digitalWrite(EEPROM_CEN, LOW);
	digitalWrite(EEPROM_OEN, LOW);
	ResetLines();
	return data;
}

void EEPROM::Write(uint16_t address, uint8_t data)
{
	digitalWrite(LED_BUILTIN, HIGH);
	SetDataMode(OUTPUT);
	SetAddress(address);
	SetData(data);
	digitalWrite(EEPROM_CEN, LOW);
	digitalWrite(EEPROM_WEN, LOW);
	delay(1);
	digitalWrite(EEPROM_WEN, HIGH);
	digitalWrite(EEPROM_CEN, HIGH);
	delay(100);
	digitalWrite(LED_BUILTIN, LOW);
}


void EEPROM::ResetLines()
{
	digitalWrite(EEPROM_WEN, HIGH);
	digitalWrite(EEPROM_OEN, HIGH);
	digitalWrite(EEPROM_CEN, HIGH);
}

void EEPROM::SetDataMode(uint8_t mode)
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(EEPROM_DATA + i, mode);
	}
}

void EEPROM::SetAddress(uint16_t address)
{
	for (int i = 0; i < 8; i++)
	{
		int off = (i < 4) ? 0 : 4;
		digitalWrite(EEPROM_CLK, LOW);
		digitalWrite(EEPROM_DATA1, !!(address & (1 << (i + off))));
		digitalWrite(EEPROM_DATA2, !!(address & (1 << (i + off + 4))));
		digitalWrite(EEPROM_CLK, HIGH);
	}
}

void EEPROM::SetData(uint8_t data)
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(EEPROM_DATA + i, !!(data & (1 << i)));
	}
}

uint8_t EEPROM::GetData()
{
	uint8_t data = 0;
	for (int i = 0; i < 8; i++)
	{
		data |= digitalRead(EEPROM_DATA + i) << i;
	}
	return data;
}

void EEPROM::SetDataRead(bool enable)
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(EEPROM_DATA + i, enable ? INPUT : OUTPUT);
	}

}


