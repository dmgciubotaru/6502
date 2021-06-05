#ifndef _AT28C256
#define _AT28C256

#include <SN74HC595.h>
#include <Arduino.h>

class AT28C256
{
public:
	AT28C256(SN74HC595* address, uint8_t rw, uint8_t data);

	void Enable();
	void Disable();

	uint8_t Read(uint16_t address);
	void Write(uint16_t address, uint8_t data);

	void DiagData();
private:
	void SetDataDir(uint8_t dir);
	uint8_t GetByte();
	void SetByte(uint8_t data);

	SN74HC595* m_address;
	uint8_t m_rw;
};

#endif