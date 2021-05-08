#pragma once

#include "stdint.h"
#include <arduino.h>

#define EEPROM_CLK A0
#define EEPROM_DATA1 A1
#define EEPROM_DATA2 A2
#define EEPROM_CEN A3
#define EEPROM_OEN A4
#define EEPROM_WEN A5
#define EEPROM_DATA 2



class EEPROM
{
public:
	EEPROM();
	
	uint8_t Read(uint16_t address);
	void Write(uint16_t address, uint8_t data);
		
	void DisableProtection();
private:
	void ResetLines();
	void SetDataMode(uint8_t mode);
	void SetAddress(uint16_t address);
	void SetData(uint8_t data);
	uint8_t GetData();
	void SetDataRead(bool enable);

}; 