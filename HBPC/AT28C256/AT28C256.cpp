#include "AT28C256.h"

#define T_ACC 1
#define T_WP  1
#define T_WC  10000


AT28C256::AT28C256(SN74HC595* address, uint8_t rw, uint8_t data)
{
	m_address = address;
	m_rw = rw;
	m_data = data;

	pinMode(m_rw, OUTPUT);
	digitalWrite(m_rw, HIGH);

	SetDataDir(INPUT);

	m_address->SetData(0, 16);
	m_address->EnableOutput(true);

}

uint8_t AT28C256::Read(uint16_t address)
{
	uint8_t data;
	SetDataDir(INPUT);
	digitalWrite(m_rw, HIGH);
	m_address->SetData(address, 16);
	delayMicroseconds(1);
	data = GetByte();
	m_address->SetData(0, 16);
	printf("R [%04x] -> %02x\n", address, data);

	return data;
}

void AT28C256::Write(uint16_t address, uint8_t data)
{
	printf("W %02x -> [%04x]\n", data, address);
	digitalWrite(m_rw, LOW);
	m_address->SetData(address, 16);
	SetDataDir(OUTPUT);
	SetByte(data);
	delayMicroseconds(T_WP);
	m_address->SetData(address - 0x8000, 16);
	SetDataDir(INPUT);
	m_address->SetData(0, 16);
	delayMicroseconds(T_WC);
	digitalWrite(m_rw, HIGH);
}

void AT28C256::SetDataDir(uint8_t dir)
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(m_data + i, dir);
	}
}

uint8_t AT28C256::GetByte()
{
	uint8_t data = 0;
	for (int i = 0; i < 8; i++)
	{
		data |= digitalRead(m_data + i) << i;
	}
	return data;
}

void AT28C256::SetByte(uint8_t data)
{
	char s[100];
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(m_data + i, !!(data & (1 << i)));
	}
}
