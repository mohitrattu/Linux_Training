#include "../shrdds.h"
#include "headers.h"

int processRequest(Infra *infra)
{
	int count,sfd,cfd,fret,ret;
	char rfd[4];
	char wfd[4];
	char client_fifo[20];
	Request r;
	Result res;

        printf("%s: Begin\n",__func__);
	
	while(1)
	{
		//if below statement is commented then server does not read request from client
		printf("%s: Going to open\n",__func__);
		sfd = open(infra->fifoName,O_RDONLY);
		if(sfd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
        	printf("%s: Opened\n",__func__);		

		count = read(sfd,&r,sizeof(Request));
		if(count == -1)
		{
			perror("read");
			close(sfd);
			exit(EXIT_FAILURE);
		}
		printf("%s: FILE ; Read Request %d",__FILE__,count);
		close(sfd);

		//////////////invoking Vendor/////////////////
		fret = fork();
		switch( fret)
        	{
                	case -1:
				perror("fork");
                       		exit(EXIT_FAILURE);
                       		break;
               		case 0:
                       		sprintf(rfd,"%d",*(infra->pipes+2));
                       		sprintf(wfd,"%d",*(infra->pipes+1));
                    		// printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
                       		execl("./adder","adder",wfd,rfd,NULL);
                       		break;
               		default:       
				write(*(infra->pipes+3),&r,sizeof(Request));
				count = read(*(infra->pipes+0),&res,sizeof(Result));
                       	
				if(count == -1)
                       		{
                               		perror("read");
                               		exit(EXIT_FAILURE);
                       		}

				sprintf(client_fifo,CLIFIFO,r.pid);
				if(access(client_fifo,F_OK) == -1)
					ret = mkfifo(client_fifo,0666);

				cfd = open(client_fifo,O_WRONLY);
				if(cfd == -1)
				{
					perror("open");
					close(cfd);
					exit(EXIT_FAILURE);
				}

				count = write(cfd,&res,sizeof(Result));
				printf("File:%s; Func:%s. Wrote Result: %d Bytes\n",__FILE__,__func__,count);
		}
	}
	printf("%s: End \n",__FILE__);
}



/*	//count = read(*(pipes+0),&r,sizeof(Request));
	//
       	if(count == -1)
        {
        	perror("read");
              //  free(pipes);
		exit(EXIT_FAILURE);
	}   
	fret = fork();
	switch( fret)
        {
                case -1:
			perror("fork");
                       	exit(EXIT_FAILURE);
                       	break;
               	case 0:
                   //    	sprintf(rfd,"%d",*(pipes+6));
                     //  	sprintf(wfd,"%d",*(pipes+5));
                    		// printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
                       //	execl("./adder","adder",wfd,rfd,NULL);
                       	break;
               	default:       
		//	write(*(pipes+7),&r,sizeof(Request));
		//	count = read(*(pipes+4),&res,sizeof(Result));
                       	
			//count = read(*(pipes+1),&res,sizeof(Result));
			if(count == -1)
			count = read(*(pipes+0),&res,sizeof(Result));
                       	{
                               	perror("read");
                               	free(pipes);
                               	exit(EXIT_FAILURE);
                       	}
			printf("File:%s; Func:%s. Read Request: %d Bytes\n",__FILE__,__func__,count);
			//printf("Pid: %d , Result:%d\n",res.pid,res.result);
        }	
	printf("%s: End \n",__FILE__);
	return count;
}*/

