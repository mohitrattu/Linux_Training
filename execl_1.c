#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd,rret,len;
	char buff[100];
	printf("%s : Begin\n",__FILE__);
	printf("argc : %d\n",argc);
	fd = atoi(argv[1]);
	printf("FD Read : %d\n",fd);
	lseek(fd,0,SEEK_SET);
	rret = read(fd,buff,100);
	if(rret == -1)
	{
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("%s : Read : %d Bytes\n",__FILE__,rret);
	printf("%s\n",buff);
	printf("%s: End \n",__FILE__);
	return 0;
}

