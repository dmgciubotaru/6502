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
	void Clock();

private:
	HANDLE m_conn;
	HANDLE m_hRecvTh;
	std::atomic<bool> m_run;

	static DWORD WINAPI RecvLoopProxy(void *ctx);
	void RecvLoop();
	
	void SendData(HBCCmd cmd, void* data = NULL, int size = 0);
};
