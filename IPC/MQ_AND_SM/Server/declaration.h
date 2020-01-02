#include<header.h>

int* CreateInfra()
{
	int i, ret;
	int *pipes;

	printf("FIle:%s; Func:%s. Begin\n",__FILE__,__func__);
	pipes = (int*)malloc(sizeof(int)*8);

	if(!pipes)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	memset(pipes,'0',sizeof(int)*8);

	for(i=0;i<8;i+=2)
	{
		ret = pipe(pipes+i);
		if(ret == -1)
		{
			perror("pipe");
			free(pipes);
			exit(EXIT_FAILURE);
		}
	}
	
	printf("FIle:%s; Func:%s. End\n",__FILE__,__func__);
	return 0;
}
