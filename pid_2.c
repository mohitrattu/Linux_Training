#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("PID:%d; Ppid:%d,func:%s: Begin\n",getpid(),getppid(),__func__);
	system("./pid");
	fork();
	printf("PID:%d; PPid:%d,func:%s: End\n",getpid(),getppid(),__func__);
	return 0;
}

