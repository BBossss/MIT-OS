#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: sleep [number ...]");
		exit(1);
	}
	printf("(nothing happens for a little while)\n");
	sleep(atoi(argv[1]));
	exit(0);
}
