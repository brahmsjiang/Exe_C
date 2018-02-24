#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#define MAXLINE 200

int retsum0(int a, ...);
int retsum1(int a, ...);
void printvar0(const char* args, ...);
void printvar1(const char* args, ...);

int main(void)
{
	//err_sys("===>%s\n","a");
	printf("sum is %d\n",retsum0(4,20,30,40,2));
	printf("sum is %d\n",retsum1(9999,20,30,40,2,-1));
	//printvar0("AA","BB","CC","");
	printvar0("AAA","BBB","CCC","DDD",(char*)0);
	printvar1("%s<=======\n","BB");
	exit(0);
}

int retsum0(int a, ...)
{
	int sum=0;
	va_list ap;
	va_start(ap,a);
	for(int i=0;i<a;i++){
		sum+=va_arg(ap,int);
	}
	va_end(ap);
	return sum;
}

int retsum1(int a, ...)
{
	int sum=0,tmp;
	va_list ap;
	va_start(ap,a);
	while((tmp=va_arg(ap,int))!=-1)
		sum+=tmp;
	va_end(ap);
	return sum;
}

void printvar0(const char* args,...)
{
	char buf[MAXLINE]={0};
	va_list ap;
	va_start(ap,args);
	while(args!=0)
	{
		strcat(buf,args);
		printf("cur buf: %s\n",buf);
		args = va_arg(ap, const char *);
		printf("cur a: %p ===>%s\n",args,args);
	}
	strcat(buf,"\n");
	fputs(buf,stdout);
	fflush(NULL);
	va_end(ap);
}

void printvar1(const char* a,...)
{
	char buf[MAXLINE]={0};
	va_list ap;
	va_start(ap,a);
	vsnprintf(buf,MAXLINE,a,ap);
	fputs(buf,stdout);
	fflush(NULL);
	va_end(ap);
}




