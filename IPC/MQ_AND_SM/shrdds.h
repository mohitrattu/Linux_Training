#ifndef SERVFIFO
#define SERVFIFO "serverFifo"
#endif

#ifndef CLIFIFO
#define CLIFIFO "cli.%d.fifo"
#endif

#ifndef KEY
#define KEY 777
#endif

#ifndef MSG_TYPE
#define MSG_TYPE 1
#endif

typedef struct{
	int pid;
	int opr;
	int opr1;
	char oper;
}Request;

typedef struct
{
	int pid;
	int result;
}Result;

typedef struct
{
	int *pipes;
	int msg_id;
	char *fifoName;
	Result *res;
}Infra;

typedef struct
{
	long msg_type;
	Result res;
}Message;

Infra* CreateInfra();

int processRequest(Infra *infra);
