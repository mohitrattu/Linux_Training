#include"../headers.h"
#include "../shrdds.h"
int main()
{
	int count,wfd,msg_id,ret;
	char client_fifo[20];
	Request r;
	Message msg;
	printf("File:%s; Func:%s. Begin\n",__FILE__,__func__);
	r.pid = getpid();
	r.oper = '+';
	r.opr1 = 33;
	r.opr = 55;
	wfd = open(SERVFIFO,O_WRONLY);
	if(wfd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	count = write(wfd,&r,sizeof(Request));
	if(count == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(wfd);
	printf("File:%s; Func:%s. Write Bytes: %d\n",__FILE__,__func__,count);
	
	msg_id = msgget(KEY,0666 |  IPC_CREAT );
	msgrcv(msg_id,&msg,sizeof(msg),MSG_TYPE,0);

	printf("File:%s; Func:%s. Result: %d End\n",__FILE__,__func__,msg.res.result);
	//:msgctl(msg_id, IPC_RMID, NULL);
	/*sprintf(client_fifo,CLIFIFO,r.pid);
	if(access(client_fifo,F_OK == -1))
			ret = mkfifo(client_fifo,0666);
	if(ret == -1)
	{
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	rfd = open(client_fifo,O_RDONLY);
	if(rfd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	count = read(rfd,&res,sizeof(Result));
        if(count == -1)
        {
                perror("read");
                exit(EXIT_FAILURE);
        }

	printf("File:%s; Func:%s. Result: %f End\n",__FILE__,__func__,res.result);
	close(rfd);
	*/
	return 0;
}
