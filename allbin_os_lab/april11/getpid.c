#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int pid_t;
	pid_t = getpid();
	printf("process ID is %d\n",pid_t);
	return 0;
}
