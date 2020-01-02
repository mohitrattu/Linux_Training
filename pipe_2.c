#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<wait.h>
#include<string.h>

int main()
{
	int fret,len,pret,wret,stat;
	char buff[] = "Raise Above Hate";
	char sfd[4];
	int arr[2];
        printf("%s: Begin\n",__FILE__);
       	pret = pipe(arr);	
	if(pret == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	//printf("%s : File Opened Successfulyy. fd : %d\n",__FILE__,fd);
        fret = fork();
        switch( fret)
        {
                case -1:
                        perror("fork");
                        exit(EXIT_FAILURE);
                        break;
                case 0:
			sprintf(sfd,"%d",arr[0]);
                       // printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
			execl("./execl_1","execl_1",sfd,NULL);
                        break;
                default:
                       // printf("PID:%d;PPID: %d,func:%s: Parent Fret:%d\n",getpid(),getppid(),__func__,fret);  
			len = strlen(buff);
			wret = write(arr[1],buff,len);
			if(wret == -1)
			{
				perror("write");
				close(arr[1]);
				exit(EXIT_FAILURE);
			}
			wait(&stat);
	}
	printf("%s: End \n",__FILE__);
	return 0;
}

