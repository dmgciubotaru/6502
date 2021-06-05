#include "HBServer.h"

#include <stdio.h>
#include <Arduino.h>


HBServer::HBServer()
{
	m_debug = false;
}

HBServer& HBServer::GetInstance()
{
	static HBServer obj;
	return obj;
}

void HBServer::EnableDebug(bool enable)
{
	m_debug = enable;
}

bool HBServer::GetDebug()
{
	return m_debug;
}

void HBServer::RecvData(void* data, size_t size, int maxRetry)
{
	int retry = 0;
	if (size > 64)
	{
		printf("SerialRead size error(%d > 64)\n", size);
	}

	while (Serial.available() < (int)size)
	{
		delay(10);
		retry++;
		if ((retry > maxRetry) && (maxRetry >= 0))
		{
			printf("Read max retry excedded\n");
			return;
		}
	}
	for (int i = 0; i < (int)size; i++)
	{
		((uint8_t*)data)[i] = Serial.read();
	}
}

void HBServer::RecvFlashData(void* data, size_t size)
{
	uint16_t pos = 0;

	while(pos < size)
	{
		int inc = min(size - pos, HBCMD_CHUNK_SIZE);
		printf("Chunk %d/%d [%d]\n", pos, size, inc);
		SendCode(HBCRet::NEXT);
		RecvData((uint8_t*)data + pos, inc);
		pos += inc;
	}
}

void HBServer::SendCode(HBCRet code)
{
	Serial.write((uint8_t)HBCMD_ACK);
	Serial.write((uint8_t)code);
}

void HBServer::Debug(const char* fmt, ...)
{
	if (m_debug)
	{
		va_list myargs;
		va_start(myargs, fmt);
		printf("[DBG] ");
		vprintf(fmt, myargs);
		printf("\n");
		va_end(myargs);
		int dummy;
		RecvData(&dummy, 1, -1);
	}
}
