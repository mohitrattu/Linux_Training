#ifndef SERVFIFO
#define SERVFIFO "serverFifo"
#endif

#ifndef CLIFIFO
#define CLIFIFO "cli.%d.fifo"
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
	float result;
}Result;

typedef struct
{
	int *pipes;
	char *fifoName;
}Infra;

typedef struct
{
	long msg_type;
	struct Result res;
}Message;

Infra* CreateInfra();

int processRequest(Infra *infra);
