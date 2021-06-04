#include "HBClient.h"

HBClient conn("COM9");

void exec(const std::string& cmd)
{
	if (!cmd.compare("exit"))
	{
		printf("Bye!\n");
		exit(1);
	}
	if (!cmd.compare("ping"))
	{
		conn.Ping();
		return;
	}
	if (!cmd.compare("dbg"))
	{
		int en = 0;
		scanf_s("%d", &en);
		conn.Dbg(!!en);
		return;
	}
	if (!cmd.compare("s"))
	{
		conn.Step();
		return;
	}
	if (!cmd.compare("reset"))
	{
		conn.Reset();
		return;
	}
	if (!cmd.compare("clk"))
	{
		int ms = 0;
		scanf_s("%d", &ms);
		conn.Clock(ms);
		return;
	}
	if (!cmd.compare("flash"))
	{
		conn.Flash("");
		return;
	}
	printf("Invalid command <%s>", cmd.c_str());
}


int main(int argc, char **argv)
{
	char buff[100];
	while (1)
	{
		printf(">");
		scanf_s("%s", buff, 100);
		buff[99] = 0x00;
		try
		{
			exec(buff);
		}
		catch (const char * err)
		{
			printf("ERR>%s", err);
		}
	}
}