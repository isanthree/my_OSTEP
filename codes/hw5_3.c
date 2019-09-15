#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open("./hw5_3.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); //O_TRUNC参数使每次打开文件总会清除文件内容 
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child
        char str[] = "hello, I am child.\n";
        write(fd, str, strlen(str));
//        printf("%s\n",str);
    } else { // parent goes down this path (main)
    	int wc = wait(NULL);
        char str[] = "goodbye, I am parent.\n";
        write(fd, str, strlen(str));
//        printf("%s\n",str);
    }
    return 0;
}
