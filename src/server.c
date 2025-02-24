#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("%d", pid);
}
