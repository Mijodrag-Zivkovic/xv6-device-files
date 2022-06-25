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
	fd = open("/dev/null", O_RDWR);
	if(fd < 0)
	{ printf("opening error\n"); exit();}
	if(argc >= 3)
	{
		niz = argv[2];
		//printf("%s\n",niz);
		//printf("%d\n",strlen(niz)*sizeof(char));
		n = write(fd,niz,sizeof(char)*strlen(niz));
		//printf("%d\n",n);
	}
	else
	{
		n = read(fd, niz, 512);
		//printf("%d\n",n);
	}
	
	close(fd);
	exit();
}


