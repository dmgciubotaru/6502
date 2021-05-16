#ifndef _SN74HC595
#define _SN74HC595

#include <arduino.h>


class SN74HC595
{
public:
	SN74HC595(uint8_t ser, uint8_t sclk, uint8_t rclk, uint8_t oen);
	void SetData(uint32_t data, uint8_t size);
	void EnableOutput(bool enable);
private:
	uint8_t m_ser;
	uint8_t m_sclk;
	uint8_t m_rclk;
	uint8_t m_oen;
};

#endif