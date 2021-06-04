#include "HBCtl.h"



HBCTL::HBCTL()
	: m_shift(HBCTL_SER, HBCTL_SRCLK, HBCTL_RCLK, HBCTL_OEN)
	, m_rom(&m_shift, HBCTL_RW, HBCTL_D0)
{
	m_timerEnabled = false;

}

void HBCTL::Loop()
{
	if (m_timerEnabled && m_timer.isReady())
	{
		digitalWrite(HBCTL_CLK, !digitalRead(HBCTL_CLK));
		m_timer.reset();
	}
}

void HBCTL::Reset()
{
	digitalWrite(HBCTL_RSTN, HIGH);
	pinMode(HBCTL_RSTN, OUTPUT);
	delay(HBCTL_RST_DELAY);
	digitalWrite(HBCTL_RSTN, LOW);
	delay(HBCTL_RST_DELAY);
	digitalWrite(HBCTL_RSTN, HIGH);
	pinMode(HBCTL_RSTN, INPUT);
}

void HBCTL::Clock(int ms)
{
	if (ms == 0)
	{
		m_timerEnabled = false;
		pinMode(HBCTL_CLK, INPUT);
	}
	else
	{
		m_timerEnabled = true;
		digitalWrite(HBCTL_CLK, LOW);
		pinMode(HBCTL_CLK, OUTPUT);
		m_timer.setInterval(ms);
	}
}

int HBCTL::Flash(uint16_t addr, uint8_t* data, uint16_t size)
{
	//int errs[100];
	int errcnt = 0;

	m_rom.Enable();

	for (uint16_t i = 0; i < size; i++)
	{
		m_rom.Write(addr + i, data[i]);
	}

	for (uint16_t i = 0; i < size; i++)
	{
		if (m_rom.Read(addr + i) != data[i])
		{
			errcnt++;
			//errs[errcnt++] = i + addr;
		}
	}

	m_rom.Disable();
	
	return errcnt;
}


