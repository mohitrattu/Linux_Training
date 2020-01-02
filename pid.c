#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("PID:%d; Ppid:%d,func:%s: Begin 1\n",getpid(),getppid(),__func__);
	printf("PID:%d; PPid:%d,func:%s: End 1\n",getpid(),getppid(),__func__);
	return 0;
}

