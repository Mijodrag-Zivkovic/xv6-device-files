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
	fd = open("/home/fajl", O_RDWR | O_CREATE);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	
	lseek(fd,10,SEEK_END);
	char miki[]="mijodrag zivkovic";
	n = write(fd,miki,strlen(miki));
	printf("upisano %d\n",n);
	lseek(fd,0,SEEK_SET);
	char arr[512];
		n = read(fd, arr, 512);
		printf("procitano %d\n",n);
		n = write(1,arr,n);
		
	close(fd);
	exit();
}
