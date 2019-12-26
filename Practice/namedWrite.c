#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
int fd;
char a[100];
mkfifo("check", 0666);
fd = open("check", O_WRONLY);
printf("Enter string\n");
scanf("%s", a);
write(fd,a,strlen(a));
close(fd);
}

