#include "HBClient.h"



HBClient::HBClient(std::string port)
{
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
}

void HBClient::Ping()
{
	SendData(HBCCmd::PING);
}

void HBClient::Clock()
{
	SendData(HBCCmd::CLOCK);
}

DWORD HBClient::RecvLoopProxy(void* ctx)
{
	((HBClient*)ctx)->RecvLoop();
	return 0;
}

void HBClient::RecvLoop()
{
	while (m_run.load())
	{
		char data[100];
		int pos = 0;
		DWORD br;
		
		while (1)
		{
			if (ReadFile(m_conn, &data[pos], 1, &br, NULL) == 0)
			{
				throw "COM read error";
			}

			if (br == 1)
			{

				if (data[pos] == '\n')
				{
					data[pos] = 0x00;
					break;
				}
				pos++;
			}
		}

		printf("< %s\n", data);
		
	}
}

void HBClient::SendData(HBCCmd cmd, void* data, int size)
{
	DWORD bw;

	WriteFile(m_conn, &cmd, sizeof(HBCCmd), &bw, NULL);
	if (size)
	{
		WriteFile(m_conn, data, size, &bw, NULL);
		FlushFileBuffers(m_conn);
	}
}

