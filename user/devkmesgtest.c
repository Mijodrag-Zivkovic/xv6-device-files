#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
	int fd;
	char *niz;
	int n;
	fd = open("/dev/kmesg", O_RDWR);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	if(argc >= 3)
	{
		niz = argv[2];
		//printf("%s\n",niz);
		//printf("%d\n",strlen(niz)*sizeof(niz));
		n = write(fd,niz,sizeof(char)*strlen(niz));
		if(n<0)
			printf("nedozvoljena operacija\n");
	}
	else
	{
		char arr[512];
		n=1;
		int i=0;
		while(1)
		{
		n = read(fd, arr, 50);
		if(n==0)
			break;
		//printf("%d\n",n);
		//printf("%s\n",arr);
		write(1,arr,n);
		for(i=0;i<50;i++)
		{arr[i]=0;}	
		}
	}
	
	close(fd);
	exit();
}


