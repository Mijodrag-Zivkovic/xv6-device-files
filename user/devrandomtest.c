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
	fd = open("/dev/random", O_RDWR);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	if(argc >= 3)
	{
		niz = argv[2];
		//printf("%s\n",niz);
		//printf("%d\n",strlen(niz)*sizeof(niz));
		//char mijodrag[]="mijodrag";
		n = write(fd,niz,strlen(niz));
		
	}
	else
	{
		char arr[512];
		n = read(fd, arr, 512);
		//printf("%d\n",n);
		//printf("%s\n",arr);
		write(1,arr,n);
	}
	
	close(fd);
	exit();
}


