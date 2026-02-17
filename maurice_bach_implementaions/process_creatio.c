#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <source> <target>\n<message>: %s\n",argv[0],argv[1]);
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    if(pid == 0)
    {
        execlp("cp", "cp",argv[1],argv[2], (char *)NULL);
        perror("exec failed");
        exit(1);
       // printf("I am a child. PID = %d\n",getpid());
    }
    else{
        //printf("I am a parent. PID = %d\n",getpid());
        wait(NULL);
        printf("copy done\n");
    }
    return 0;
}
