/*
 Name:		HBPC.ino
 Created:	14/05/2021 6:45:35 PM
 Author:	dmgci
*/

#include "utils.h"
#include "HBCtl.h"
#include "HBServer.h"


HBCTL hbCtl;
HBServer& hbServ = HBServer::GetInstance();

#define MAX_RETRY_READ 5000


void setup() 
{
	Serial.begin(9600);
	delay(1000);
	printf("HBPC ready!\n");
}

void loop() 
{
	hbCtl.Loop();
}


void serialEvent() 
{
	while (Serial.available())
	{
		char c;
		HBCCmd cmd;
		hbServ.RecvData(&c, 1);
		cmd = HBCCmd(c);
		switch (cmd)
		{
			case HBCCmd::PING:
			{
				hbServ.SendCode(HBCRet::OK);
				break;
			};
			case HBCCmd::DBG:
			{
				uint8_t enabled;
				hbServ.RecvData(&enabled, 1);
				hbServ.EnableDebug(enabled);
				printf("Dbg %d\n", enabled);
				hbServ.SendCode(HBCRet::OK);
				break;
			}
			case HBCCmd::DIAG:
			{
				bool dbg;
				HBCDiag type;
				hbServ.RecvData(&type, 1);
				
				dbg = hbServ.GetDebug();
				hbServ.EnableDebug(true);
				hbCtl.Diag(type);
				hbServ.EnableDebug(dbg);

				hbServ.SendCode(HBCRet::OK);
				break;
			}
			case HBCCmd::RESET:
			{
				hbCtl.Reset();
				hbServ.SendCode(HBCRet::OK);
				break;
			}
			case HBCCmd::CLOCK:
			{
				uint16_t ms;
				hbServ.RecvData(&ms, 2);
				hbCtl.Clock(ms);
				hbServ.SendCode(HBCRet::OK);
				break;
			}
			case HBCCmd::STEP:
			{
				hbCtl.Step();
				break;
			}
			case HBCCmd::FLASH:
			{
				uint16_t size;
				uint16_t addr;
				uint8_t data[0x100];

				hbServ.RecvData(&addr, 2);
				hbServ.RecvData(&size, 2);
				hbServ.RecvFlashData(data, size);
				int err = hbCtl.Flash(addr, data, size);

				printf("Write @%04x > Size %02x errcnt %d\n", addr, size, err);
				hbServ.SendCode(HBCRet::OK);
				break;
			}

			default:
			{
				printf("Invalid command %x\n", (int)cmd);
				break;
			}
		}
	}
}
