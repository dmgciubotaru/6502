#ifndef _HBCTL_H
#define _HBCTL_H

#include <arduino.h>
#include <SN74HC595.h>
#include <AT28C256.h>
#include <simpletimer.h>

#define HBCTL_D0	A0
#define HBCTL_SER	2
#define HBCTL_OEN	3
#define HBCTL_RCLK	4
#define HBCTL_SRCLK	5
#define HBCTL_RW	6
#define HBCTL_RSTN	7
#define HBCTL_CLK	8

#define HBCTL_RST_DELAY 1

class HBCTL
{
public:
	HBCTL();
	void Loop();
	void Reset();
	void Clock(int ms);
	int Flash(uint16_t addr, uint8_t * data, uint16_t size);


private:
	bool m_enabled;
	SN74HC595 m_shift;
	AT28C256 m_rom;
	SimpleTimer m_timer;
	bool m_timerEnabled;

};

#endif