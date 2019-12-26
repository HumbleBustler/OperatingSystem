#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
	int main(int argc, char *argv[])
	{
	int pipefd[2],i;
	char buf[20],buf1[20];
	pipe(pipefd);
		write(pipefd[1], "Hello World!", 13);
		write(pipefd[1], "Hello India!", 13);
				for (i=0; i<2; i++)
				{
				read(pipefd[0], buf, 13);
				printf("%s\n", buf);
				}
		close(pipefd[0]);
		close(pipefd[1]);
	return 0;
}
