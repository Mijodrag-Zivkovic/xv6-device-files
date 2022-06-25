#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"
#include "kernel/lseek.h"

int
main(int argc, char *argv[])
{

	/*char * input;
	char * output;
	char * bs;
	char * count;
	char * skip;
	char * seek; */
	int i;
	int fdi=0;
	int fdo=1;
	int bs = 512;
	int count = -1;
	int skip = 0;
	int seek = 0;
	char * s;
	for(i=1;i<argc;i++)
	{
		if(*argv[i]=='i')
		{
			s = (argv[i]+3);
			fdi=open(s, O_RDWR);
			if(fdi<0)
				printf("greske\n");
		}
		else if(*argv[i]=='o')
		{
			s = (argv[i]+3);
			fdo=open(s, O_RDWR | O_CREATE);
			if(fdo<0)
				printf("greska out\n");
		}
		else if(*argv[i]=='c')
		{
			s = (argv[i]+6);
			count = atoi(s);
		}
		else if(*argv[i]=='b')
		{
			s = (argv[i]+3);
			bs = atoi(s);
		}
		else if(*argv[i]=='s' & *(argv[i]+1)=='k')
		{
			s = (argv[i]+5);
			skip = atoi(s);
		}
		else
		{
			s = (argv[i]+5);
			seek = atoi(s);
		}
		
	}
	int n,m;
	char niz[bs];
	lseek(fdi,skip*bs,SEEK_SET);
	lseek(fdo,seek*bs,SEEK_SET);
	if(count < 0)
	{
		
	   	while(1)
	   	{
			
			n=read(fdi,niz,bs);
			//printf("%d\n",n);
			if(n==0)
			break;
			m=write(fdo,niz,n);
	   	}
	}
	else
	{
		while(count>0)
		{
			n=read(fdi,niz,bs);
			
			m=write(fdo,niz,n);
			count--;
		}
	}

	close(fdi);
	close(fdo);
	exit();
}


