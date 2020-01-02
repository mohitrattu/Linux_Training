#include "../shrdds.h"
#include "headers.h"

int main()
{
	int count;
	//int *pipes;
	//char rfd[4];
	//char wfd[4];
	int rfd,wfd;
	Infra *infra;
	//char *myfifo = "server";
	//char *myfifo2 = "client";
	Request r;
	Result res;
	
	//if(access(myfifo,F_OK) == -1)
	//		mkfifo(myfifo,0666);

	//if(access(myfifo2,F_OK) == -1)
	//		mkfifo(myfifo,0666);

	infra = CreateInfra();
        printf("%s: Begin\n",__FILE__);
       		
	while(1)
	{
		
		processRequest(infra);
		/*fret = fork();
		switch( fret)
        	{
                	case -1:
                        	perror("fork");
                        	exit(EXIT_FAILURE);
                        	break;
                	case 0:
                        	//sprintf(rfd,"%d",*(pipes+2));
                        	//sprintf(wfd,"%d",*(pipes+1));
				rfd = open(myfifo,O_RDONLY);
				wfd = open(myfifo2,O_WRONLY);
                       		// printf("PID:%d;PPID: %d,func:%s: Child Fret:%d\n",getpid(),getppid(),__func__,fret);
                        	execl("./rc1","rc1",wfd,rfd,NULL);
                        	break;
                	default:
				rfd = open(myfifo2,O_RDONLY);
				processRequest(pipes,rfd);
				wfd = open(myfifo,O_WRONLY);
				count = write(wfd,&res,sizeof(Result));
                        	if(count == -1)
                        	{
                                	perror("write");
                                	free(pipes);
                                	exit(EXIT_FAILURE);
                        	}
        	}*/	

	}
	printf("%s: End \n",__FILE__);
	return 0;
}

