#pragma once

#include <string>
#include <atomic>
#include <Windows.h>

#include "..\common\HBDefs.h"

class HBClient
{
public:
	HBClient(std::string port);
	void Ping();
	void Dbg(bool enalbed);
	void Step();
	void Reset();
	void Clock(uint16_t ms);
	void Flash(const std::string& path);
	void Diag(HBCDiag type);

private:
	bool m_dbg;
	HANDLE m_conn;
	HANDLE m_hRecvTh;
	HANDLE m_evAck;
	std::atomic<bool> m_run;
	std::atomic<HBCRet> m_ackCode;

	void SendFlashData(uint16_t addr, uint8_t* data, uint16_t size);

	static DWORD WINAPI RecvLoopProxy(void *ctx);
	void RecvLoop();
	void RecvData(uint8_t* data, size_t size);

	void SendData(void *data, size_t size);
	template <typename T>
	void SendData(T data)
	{
		SendData(&data, sizeof(data));
	}

	HBCRet GetCode(int timeout = 5);
	std::string GetCodeText(HBCRet code);

};

