#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 int main(int argc, char *argv[])
{
pid_t pid;
int p[2];
char buf[20];
pipe(p);
	pid=fork();
	if(pid==0)
		{
			printf("You are in child process\n");
			read(p[0], buf, 13);
			printf("whatever you write in parent process raed by child is:-%s\n", buf);
		}
	else
	{
		write(p[1], "Hello World!", 13);
	}
	close(p[0]);
	close(p[1]);
}
