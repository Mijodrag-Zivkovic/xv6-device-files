#include "types.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#define KMESGBUFFSIZE 512*12

static char buff1[512*12];
static int offset = 0;
static int brojac = 0;
static int buflength = 0;

void mojwrite(char c)
{
	if(brojac<512*12)
	{
		buff1[brojac] = c;
		brojac++;
		buflength++;
	}
}


int devkmesgread(struct inode *ip, char *buf, int n, int off)
{	
	int i=0;
	if(buflength < n)
	n=buflength-off;
	for(i=0;i<n && (off+i)<brojac;i++)
	{
		buf[i]=buff1[off+i];
		//offset++;
	}
	//cprintf("brojac %d\n",brojac);
	return i;
}

int devkmesgwrite(struct inode *ip, char *buf, int n, int off)
{
	
	return -1;

}

int devkmesginit(void)
{
	devsw[DEVKMESG].read = devkmesgread;
	devsw[DEVKMESG].write = devkmesgwrite;
}

