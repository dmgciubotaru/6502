#include "HBClient.h"



HBClient::HBClient(std::string port)
{
	m_dbg = false;

	std::string path = R"(\\.\)" + port ;
	m_conn = CreateFileA(path.c_str(), GENERIC_READ | GENERIC_WRITE, 
		0, NULL, OPEN_EXISTING, NULL, NULL);
	if (m_conn == INVALID_HANDLE_VALUE)
	{
		throw "Cannot open port";
	}

	m_run.store(true);

	m_hRecvTh = CreateThread(NULL, 0, HBClient::RecvLoopProxy, this, 0, NULL);
	if (m_hRecvTh == NULL)
	{
		throw "Cannot create thread";
	}

	m_evAck = CreateEvent(NULL, FALSE, FALSE, NULL);
}

void HBClient::Ping()
{
	SendData(HBCCmd::PING);
	printf("%s\n",GetCodeText(GetCode()).c_str());
}

void HBClient::Dbg(bool enalbed)
{
	SendData(HBCCmd::DBG);
	SendData((uint8_t)enalbed);
	auto code = GetCode();
	if (code == HBCRet::OK)
	{
		m_dbg = enalbed;
	}
	printf("%s\n", GetCodeText(code).c_str());
}

void HBClient::Step()
{
	SendData(HBCCmd::STEP);
}

void HBClient::Reset()
{
	SendData(HBCCmd::RESET);
	printf("%s\n", GetCodeText(GetCode()).c_str());
}

void HBClient::Clock(uint16_t ms)
{
	SendData(HBCCmd::CLOCK);
	SendData(ms);
	printf("%s\n", GetCodeText(GetCode()).c_str());
}

void HBClient::Flash(const std::string& path1)
{
	std::string path = R"(C:\work\6502\HBOS\main)";
	HANDLE f = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	DWORD br;
	uint8_t data[0x100];

	ReadFile(f, data, 0x100, &br, NULL);
	SendFlashData(0x8000 , data, 0x100);
	

	SetFilePointer(f, 0x7f00, NULL, FILE_BEGIN);
	ReadFile(f, data, 0x100, &br, NULL);
	SendFlashData(0xFF00 , data, 0x100);
	
}

void HBClient::SendFlashData(uint16_t addr, uint8_t* data, uint16_t size)
{
	
	ResetEvent(m_evAck);

	SendData(HBCCmd::FLASH);
	SendData(addr);
	SendData(size);

	size_t pos = 0;

	while (pos < size)
	{
		HBCRet code = GetCode();
		int inc = min(size - pos, 32);
		if (code != HBCRet::NEXT)
		{
			throw "Response error: " + GetCodeText(code);
		}
		SendData(&data[pos], inc);
		pos += inc;
	}
	printf("%s\n", GetCodeText(GetCode(20)).c_str());
}

DWORD HBClient::RecvLoopProxy(void* ctx)
{
	((HBClient*)ctx)->RecvLoop();
	return 0;
}

void HBClient::RecvData(uint8_t* data, size_t size)
{
	DWORD br;
	size_t pos = 0;

	while (pos < size)
	{
		if (ReadFile(m_conn, &data[pos], size - pos, &br, NULL) == 0)
		{
			//throw "COM read error";
		}

		pos += br;
	}
}

void HBClient::SendData(void* data, size_t size)
{
	DWORD bw;

	WriteFile(m_conn, data, size, &bw, NULL);
	if (bw != size)
	{
		throw "COM write failed";
	}
	FlushFileBuffers(m_conn);
}

HBCRet  HBClient::GetCode(int timeout)
{
	if (WaitForSingleObject(m_evAck, 1000 * timeout) != WAIT_OBJECT_0)
	{
		throw "Wait error";
	}
	return m_ackCode.load();
}

std::string HBClient::GetCodeText(HBCRet code)
{
	switch (code)
	{
	case HBCRet::OK:
		return "OK";
	default:
		return "Invalid code" ;
	}
}

void HBClient::RecvLoop()
{
	uint8_t data[100];
	int pos = 0;

	while (m_run.load())
	{
		
		while (1)
		{
			RecvData(&data[pos], 1);

			switch (data[pos])
			{
			case HBCMD_ACK:
			{
				uint8_t code;
				RecvData(&code, 1);
				m_ackCode.store((HBCRet)code);
				SetEvent(m_evAck);
				break;
			}
			case '\n':
			{
				data[pos] = 0x00;
				printf("< %s\n", data);
				pos = 0;
				break;
			}
			default:
			{
				pos++;
			}

			}
		}		
	}
}
//
//void HBClient::SendData(void* data, int size)
//{
//	DWORD bw;
//
//	WriteFile(m_conn, data, size, &bw, NULL);
//	if (bw != size)
//	{
//		throw "COM write failed";
//	}
//	FlushFileBuffers(m_conn);
//}

