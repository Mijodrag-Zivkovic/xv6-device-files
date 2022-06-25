#include "types.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "buf.h"
#define min(a, b) ((a) < (b) ? (a) : (b))
//#define DISKSIZE 512
//static char buff1[512];

static struct buf *bp;

int devdiskread(struct inode *ip, char *dst, int n, int off)
{
	/*off+=201;
	cprintf("%d\n",off);
	buff = bread(1,off);
	int i;
	for(i=0;i<512;i++)
	{
		buf[i] = buff->data[i];
	}
	brelse(buff);
	return n; */

	int tot;int m;
	for(tot=0; tot<n; tot+=m, off+=m, dst+=m){
		bp = bread(ip->dev, off/BSIZE);
		m = min(n - tot, BSIZE - off%BSIZE);
		memmove(dst, bp->data + off%BSIZE, m);
		brelse(bp);
	}
	return n;
}

int devdiskwrite(struct inode *ip, char *src, int n, int off)
{
	/*
	off+=201;
	bp = bread(1,off);
	int i;
	//cprintf("%d\n",strlen(buf));
	for(i=0;i<strlen(buf) && i<512;i++)
	{
		bp->data[i]=buf[i];
	}
	bwrite(bp);
	brelse(bp); */
	int tot;int m;
	for(tot=0; tot<n; tot+=m, off+=m, src+=m)
	{
		
		bp = bread(ip->dev, off/BSIZE);
		
		m = min(n - tot, BSIZE - off%BSIZE);
		memmove(bp->data + off%BSIZE, src, m);
		bwrite(bp);
		brelse(bp);
	}
	return n;
}

int devdiskinit(void)
{
	devsw[DEVDISK].read = devdiskread;
	devsw[DEVDISK].write = devdiskwrite;
}

