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
	fd = open("/dev/zero", O_RDWR);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	if(argc >= 3)
	{
		niz = argv[2];
		//printf("%s\n",niz);
		//printf("%d\n",strlen(niz)*sizeof(niz));
		n = write(fd,niz,sizeof(char)*strlen(niz));
		//printf("%d\n",n);
		//write(1,niz,n);
	}
	else
	{
		char arr[]="hello";
		n = read(fd, arr, sizeof(char)*strlen(arr));
		//printf("%d\n",n);
		write(1,arr,n);
		//printf("%s\n",arr);
	}
	
	close(fd);
	exit();
}


