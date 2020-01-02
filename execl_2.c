#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<wait.h>
#include<string.h>

int main()
{
	int fret,len,fd,wret,stat;
	char buff[] = "How you doing?";
	char sfd[4];
        printf("%s: Begin\n",__FILE__);
       	fd = open("sup.txt",O_RDWR);	
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("%s : File Opened Successfulyy. fd : %d\n",__FILE__,fd);
        fret = fork();
        switch( fret)
        {
                case -1:
                        perror("fork");
                        exit(EXIT_FAILURE);
                        break;
                case 0:
			sprintf(sfd,"%d",fd);
                       // printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
			execl("./execl_1","execl_1",sfd,NULL);
                        break;
                default:
                       // printf("PID:%d;PPID: %d,func:%s: Parent Fret:%d\n",getpid(),getppid(),__func__,fret);  
			len = strlen(buff);
			wret = write(fd,buff,len);
			if(wret == -1)
			{
				perror("write");
				close(fd);
				exit(EXIT_FAILURE);
			}
			wait(&stat);
	}
	//printf("PID:%d; PPid:%d,func:%s: End 2\n",getpid(),getppid(),__func__);
	return 0;
}

