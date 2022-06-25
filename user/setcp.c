#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	char *x1,*y1;
	x1 = argv[1];
	y1 = argv[2];
	//printf("%s %s\n",x1,y1);
	int x = atoi(x1);
	int y = atoi(y1);
	//printf("%d %d\n",x,y);
	if(setcp(x,y)<0)
		printf("%s\n","error!");
	exit();
}
