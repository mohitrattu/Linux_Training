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

Infra* CreateInfra();

int processRequest(Infra *infra);
