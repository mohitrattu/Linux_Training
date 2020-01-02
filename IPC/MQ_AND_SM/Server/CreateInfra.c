#include "../headers.h"
#include"../shrdds.h"

Infra* CreateInfra()
{
	int i, ret,shm_id;
	Infra *infra;

	printf("FIle:%s; Func:%s. Begin\n",__FILE__,__func__);
	infra = (Infra*)malloc(sizeof(Infra));
	if(!infra)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	infra->pipes = (int*)malloc(sizeof(int)*4);
 	 
	if(!infra->pipes)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }


	infra->fifoName = (char*)malloc(sizeof(char)*20);

	if(!infra->fifoName)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }

	memset(infra->fifoName,'\0',20);
	strcpy(infra->fifoName,SERVFIFO);

	for(i=0;i<2;i+=2)
	{
		ret = pipe(infra->pipes+i);
		if(ret == -1)
		{
			perror("pipe");
			//free(pipes);
			exit(EXIT_FAILURE);
		}
	}
	if(access(infra->fifoName,F_OK) == -1)
	{
		ret = mkfifo(infra->fifoName,0666);
		if(ret == -1)
		{
			perror("mkfifo");
			exit(EXIT_FAILURE);
		}
	}

	infra->msg_id = msgget(KEY,0666 | IPC_CREAT);
		
	shm_id = shmget(KEY,1024,0666);
	infra->res = (Result* )shmat(shm_id,(void*)0,0);

	
	printf("FIle:%s; Func:%s. End\n",__FILE__,__func__);
	return infra;
}
