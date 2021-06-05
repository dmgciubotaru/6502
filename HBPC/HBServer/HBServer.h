#ifndef _HB_SERVER
#define _HB_SERVER

#include <stddef.h>
#include <stdint.h>
#include "..\common\HBDefs.h"

#define MAX_RETRY_READ 5000

class HBServer
{
public:
	static HBServer& GetInstance();
	void EnableDebug(bool enable);
	bool GetDebug();
	void RecvData(void *data, size_t size, int maxRetry = MAX_RETRY_READ);
	void RecvFlashData(void* data, size_t size);
	void SendCode(HBCRet code);
	void Debug(const char *fmt, ... );
private:
	HBServer();
	bool m_debug;
};

#endif