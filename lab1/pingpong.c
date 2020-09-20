#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{
	int pid;
	int fds[2];
	char buf[10];

	pipe(fds);

	pid = fork();
	if (pid == 0)
	{	
		read(fds[0], buf, 1);
		printf("%d: received ping\n", getpid());
		write(fds[1], "", 1);
	}
	else
	{
		write(fds[1], "", 1);
		sleep(5);
		read(fds[0], buf, 1);
		printf("%d: received pong\n", getpid());
	}
	exit(0);
}
