#include "SN74HC595.h"

SN74HC595::SN74HC595(uint8_t ser, uint8_t sclk, uint8_t rclk, uint8_t oen)
{
	m_ser = ser;
	m_sclk = sclk;
	m_rclk = rclk;
	m_oen = oen;

	pinMode(m_ser, OUTPUT);
	pinMode(m_sclk, OUTPUT);
	pinMode(m_rclk, OUTPUT);
	pinMode(m_oen, OUTPUT);

	digitalWrite(m_ser, LOW);
	digitalWrite(m_sclk, LOW);
	digitalWrite(m_rclk, LOW);
	digitalWrite(m_oen, HIGH);
}

void SN74HC595::SetData(uint32_t data, uint8_t size)
{
	for (int i = 0; i < size; i++)
	{
		
		digitalWrite(m_ser, !!(data& (1 << i)));
		digitalWrite(m_sclk, HIGH);
		digitalWrite(m_sclk, LOW);
	}
	digitalWrite(m_rclk, HIGH);
	digitalWrite(m_rclk, LOW);
}

void SN74HC595::EnableOutput(bool enable)
{
	if (enable)
	{
		digitalWrite(m_oen, LOW);
	}
	else
	{
		digitalWrite(m_oen, HIGH);
	}
}

