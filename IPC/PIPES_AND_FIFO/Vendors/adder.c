#include"headers.h"
#include "../shrdds.h"
int main(int argc, char *argv[])
{
	int count, wfd,rfd;
	Request r;
	Result res;
	printf("File:%s; Func:%s. Begin\n",__FILE__,__func__);
	
	if(argc != 3)
	{
		printf("File:%s; Func:%s. USAGE: Insufficeient Arguments\n",__FILE__,__func__);
		exit(EXIT_FAILURE);
	}
	wfd = atoi(argv[1]);
	rfd = atoi(argv[2]);
	count = read(rfd,&r,sizeof(Request));
	printf("%d\n",r.opr);
	printf("%d\n",r.opr1);
	printf("%c\n",r.oper);
	if(count == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	if(r.oper == '+')
	{
		res.result = r.opr + r.opr1;
		res.pid = r.pid;
	}
	printf("%f\n",res.result);
	count = write(wfd,&res,sizeof(Result));

	if(count == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	printf("File:%s; Func:%s.End\n",__FILE__,__func__);
	return 0;
}
