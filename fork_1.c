#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 	pid_t fret;
	int i,n,wret,wptr;
	printf("PID:%d; Ppid:%d,func:%s: Begin\n",getpid(),getppid(),__func__);
	fret = fork();
	switch( fret)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;
		case 0:
			printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
			n = 10;
			break;
		default:
			printf("PID:%d;PPID: %d,func:%s: Parent Fret:%d\n",getpid(),getppid(),__func__,fret);	
			n = 20;
		
	}
	//printf("PID:%d;PPID:%d,func:%s END\n",getpid(),getppid(),__func__);
	for(int i=0;i<n;i++)
	{
		printf("PID:%d;PPID:%d Running %d \n",getpid(),getppid(),i);
		sleep(1);
	}
	if(fret)
	{
		wret = wait(&wptr);
		printf("PID:%d;PPID:%d,Func:%s;PID of Child Finished:%d\n",getpid(),getppid(),__func__,wret);
		if(WIFEXITED(wptr))
			printf("PID:%d;PPID:%d,Func:%s;Exit code:%d\n",getpid(),getppid(),__func__,WIFEXITED(wptr));
	}
	printf("PID:%d; PPid:%d,func:%s: End\n",getpid(),getppid(),__func__);
	exit (n);
}

