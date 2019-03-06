#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
printf("myfork test\n");
exit(0);
}
