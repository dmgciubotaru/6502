#include "HBClient.h"

int loop(const char *port)
{

	HBClient conn("COM3");
	
	char buff[100];

	while (1)
	{
		std::string cmd;
		scanf_s("%s", buff, 100);
		buff[99] = 0x00;
		cmd = buff;
		if (!cmd.compare("exit"))
		{
			printf("Bye!\n");
			exit(1);
		}
		if (!cmd.compare("ping"))
		{
			conn.Ping();
			continue;
		}
		if (!cmd.substr(0, 3).compare("clk"))
		{
			conn.Clock();
			std::string arg = cmd.substr(3);
			if (!arg.compare("on"));
		}

		printf("Invalid command <%s>", cmd.c_str());
	}
}

int main(int argc, char **argv)
{
	try
	{
		loop("COM3");

	}
	catch(const char* ex)
	{
		printf("ERR>%s", ex);
	}
}