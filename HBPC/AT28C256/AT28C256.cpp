#include "AT28C256.h"
#include "HBServer.h"

#define T_ACC 1
#define T_WP  1
#define T_WC  10000

static HBServer& hbServ = HBServer::GetInstance();

int PIN_DATA[] = { A0, A1, A2, A3, A4, A5, 11, 12 };

AT28C256::AT28C256(SN74HC595* address, uint8_t rw, uint8_t data)
{
	m_address = address;
	m_rw = rw;

	pinMode(m_rw, OUTPUT);
	digitalWrite(m_rw, HIGH);

	SetDataDir(INPUT);

	m_address->SetData(0, 16);
	m_address->EnableOutput(false);
}

void AT28C256::Enable()
{
	m_address->EnableOutput(true);
}

void AT28C256::Disable()
{
	m_address->EnableOutput(false);
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

	return data;
}

void AT28C256::Write(uint16_t address, uint8_t data)
{
	digitalWrite(m_rw, LOW);
	hbServ.Debug("Set RW -> LOW");
	m_address->SetData(address, 16);
	hbServ.Debug("Set Address to %04x", address);
	SetDataDir(OUTPUT);
	SetByte(data);
	hbServ.Debug("Set Data to %02x", data);
	delayMicroseconds(T_WP);
	m_address->SetData(address - 0x8000, 16);
	hbServ.Debug("Unset CS");
	SetDataDir(INPUT);
	m_address->SetData(0, 16);
	hbServ.Debug("Clear data");
	delayMicroseconds(T_WC);
	digitalWrite(m_rw, HIGH);
	hbServ.Debug("Set RW -> High");
}

void AT28C256::SetDataDir(uint8_t dir)
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(PIN_DATA[i], dir);
	}
}

uint8_t AT28C256::GetByte()
{
	uint8_t data = 0;
	for (int i = 0; i < 8; i++)
	{
		data |= digitalRead(PIN_DATA[i]) << i;
	}
	return data;
}

void AT28C256::SetByte(uint8_t data)
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(PIN_DATA[i], !!(data & (1 << i)));
	}
}
