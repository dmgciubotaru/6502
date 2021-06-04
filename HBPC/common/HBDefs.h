#ifndef _HBDEFS_H
#define _HBDEFS_H

#include <stdint.h>


#define HBCMD_ACK	0x06
#define HBCMD_CHUNK_SIZE 32

enum class HBCRet : uint8_t
{
	INVALID,
	OK,
	NEXT,
};


enum class HBCCmd : uint8_t
{
	PING,
	DBG,
	STEP,
	RESET,
	CLOCK,
	FLASH,
};




#endif