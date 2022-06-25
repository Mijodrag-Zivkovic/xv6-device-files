#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	int x,y;
	getcp(&x,&y);
	printf("x = %d y = %d\n", x,y);
	exit();
}
