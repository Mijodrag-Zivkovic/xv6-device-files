#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"
#include "kernel/lseek.h"
int
main(int argc, char *argv[])
{
	int fd;
	char *niz;
	int n;
	fd = open("/dev/disk", O_RDWR);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	if(argc >= 3)
	{
		niz = argv[2];
		//printf("%s\n",niz);
		//printf("%d\n",strlen(niz)*sizeof(niz));
		lseek(fd,512*202,SEEK_SET);
		n = write(fd,niz,strlen(niz));
		lseek(fd,-4,SEEK_CUR);
		n = write(fd,niz,strlen(niz));
		if(n<0)
			printf("nedozvoljena operacija\n");
	}
	else
	{
		char arr[512];
		lseek(fd,512*202,SEEK_SET);
		n = read(fd, arr, 512);
		//printf("%d\n",n);
		//printf("%s\n",arr);
		write(1,arr,n);
	}
	
	close(fd);
	exit();
}


