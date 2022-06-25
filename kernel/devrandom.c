#include "types.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "defs.h"
#define bufsize 256
char buffer[bufsize];

int abs(int x)
{
	if(x<0)
	x=-x;
	return x;
}

int pow(int os, int st)
{
	int rez = 1;int i;
	for(i=0;i<st;i++)
	rez=rez*os;
	return rez;
}

int pomocna = 0;
void randomhelp(int x,int y)
{
	//cprintf("%c\n",y);
	int i;
	buffer[0]= (x*y)%255+1;
	for(i=1;i<bufsize;i++)
	{
		if(pomocna == 0)
		{
			int z = pow(x-i,7)+pow(i-y,6)+1;
			buffer[i] = abs(z)%255+1;
			pomocna++;
		}
		else if(pomocna == 1)
		{
			int z = pow(i-buffer[i-1],7)+pow(i,6)+1;
			buffer[i] = abs(z)%255+1;
			pomocna++;
		}
	if(pomocna == 2)
	pomocna=0;
	}
	//pomocna++;
	//if(pomocna == 2)
	//pomocna=0;
}

int devrandomread(struct inode *ip, char *buf, int n)
{
	int i;
	for(i=0;i<bufsize && i<n;i++)
	{
		buf[i]=buffer[i];
	}
	int r = i;
	pomocna=0;
	if(i<n)
	{
	    for(;i<n;i++)
	    {
		if(pomocna == 0)
		{
			int z = pow(ticks-i,7)+pow(i-buf[i-1],6)+1;
			buf[i] = abs(z)%255+1;
			pomocna++;
		}
		else if(pomocna == 1)
		{
			int z = pow(i-buf[i-1],8)+pow(i,6)+1;
			buf[i] = abs(z)%255+1;
			pomocna++;
		}
		pomocna++;
	    if(pomocna == 2)
	    pomocna=0;
	    }
	    
	    
	} 
	randomhelp(ticks,buf[i-1]);
	return i;
}

int devrandomwrite(struct inode *ip, char *buf, int n)
{
	int i;
	buffer[0]= abs((ticks*buf[0]))%255+1;
	for(i=1;i<n && i<bufsize;i++)
	{
		int y = buf[i];
		if(pomocna == 0)
		{
			int z = pow(ticks-i,7)+pow(i-y,6)+1;
			buffer[i] = abs(z)%255+1;
			//pomocna++;
		}
		else if(pomocna == 1)
		{
			int z = pow(i-buf[i-1],7)+pow(i,6)+1;
			buffer[i] = abs(z)%255+1;
			//pomocna++;
		}
		if(pomocna == 2)
		pomocna=0;
		pomocna++;
	}
	int r = i;
	if(i<bufsize)
	{
	    for(;i<bufsize;i++)
	    {
		if(pomocna == 0)
		{
			int z = pow(ticks-i,7)+pow(i-buffer[i-1],6)+1;
			buffer[i] = abs(z)%255+1;
			pomocna++;
		}
		else if(pomocna == 1)
		{
			int z = pow(i-buffer[i-1],7)+pow(i,6)+1;
			buffer[i] = abs(z)%255+1;
			pomocna++;
		}
	    }
	    pomocna++;
	    if(pomocna == 2)
	    pomocna=0;
	    
	} 
	return r;
}

void devrandominit(void)
{
	devsw[DEVRANDOM].read = devrandomread;
	devsw[DEVRANDOM].write = devrandomwrite;
	int i;
	//for(i=0;i<512;i++)
	//{
		//buffer[i]= i%255+1;
	//}
}

