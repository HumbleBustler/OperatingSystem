#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd, i=0,c=0;
	char buf[1000];
	fd = open("check", O_RDONLY);
	read(fd, buf, 1000);
	printf("Rec: %s\n", buf);
	close(fd);

}
