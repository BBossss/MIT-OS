#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{
	int fds[2];
	int i, pid, n = 34;
	int primes[n], buf[n];
	for (i = 0; i < n; i++)
	{
		primes[i] = i + 2;
	}	
		

	while(n != 0){			
		printf("prime %d\n", primes[0]);	
		pipe(fds);
		pid = fork();
		if (pid == 0)
		{
			read(fds[0], primes, n * sizeof(int));
			close(fds[0]);
			close(fds[1]);
		}
		else
		{
			int count = 0;
			for (i = 1; i < n; i++)
			{
				if (primes[i] % primes[0] != 0)
				{
					buf[count++] = primes[i];
				}
			}
			n = count;
			write(fds[1], buf, n * sizeof(int));
			wait(0);
			close(fds[0]);
			close(fds[1]);
		}
	}
	exit(0);
}
