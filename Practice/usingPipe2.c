#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    int pipefd[2],n;
    
    char buff[100];
    
    if(pipe(pipefd)<0) perror("pipe error");
    printf("read fd=%d, write fd=%d\n",pipefd[0],pipefd[1]);
    if(write(pipefd[1],"hello world\n",12) != 12) perror("write error");
    
    if((n=read(pipefd[0],buff,sizeof(buff)))<=0) perror("read error");
    write(1,buff,n);
    
 }