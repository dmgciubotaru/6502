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
	void RecvData(void *data, size_t size);
	void RecvFlashData(void* data, size_t size);
	void SendCode(HBCRet code);
	void Debug(const char *fmt, ... );
private:
	HBServer();
	bool m_debug;
};

#endif