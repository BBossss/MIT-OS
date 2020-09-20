#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{	
	char *buf[32];
	char buf2[512];
	char buf3[32][32];
	
	for (int i = 0; i < 32; i++)
	{
		buf[i] = buf3[i];
	}
	
	for (int i = 1; i < argc; i++)
	{
		strcpy(buf[i - 1], argv[i]);
	}
	
	int n;
	// read char from 0
	while ((n = read(0, buf2, sizeof(buf2))) > 0)
	{
		int pos = argc - 1;
		char *next = buf3[pos];
		for (char *c = buf2; *c; c++)
		{
			if (*c == ' ' || *c == '\n')
			{
				*next = '\0';
				next = buf3[++pos];
			}
			else
			{
				*next++ = *c;
			}
		}
		*next = '\0';
		buf[pos+1] = 0;
		if (fork() == 0)
		{
			exec(buf[0], buf);
		}
		else
		{
			wait(0);	
		}
	}
	if (n < 0)
	{
		printf("xargstest: read error\n");
		exit(0);
	}
	exit(0);
}
