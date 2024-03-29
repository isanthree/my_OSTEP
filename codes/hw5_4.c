//调用execvp()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, int *argv[])
{
	printf("hello world (pid:%d)\n",(int)getpid());
	int rc = fork();
	if(rc < 0)  //fork failed; exit
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if(rc == 0)  //child (new process)
	{
		printf("hello, I am child (pid:%d)\n",(int)getpid());
		char *myargs[3];
		myargs[0] = strdup("ls");  //program: "wc" (word count) me:这个是系统程序吗，依据哪个路径去找呢？ 
		myargs[1] = strdup("hw5_4.c");  //argument: file to count
		myargs[2] = NULL;  //mark end of array
		execvp(myargs[0],myargs);  //runs word count
		printf("this shouldn't print out\n");  //me: why???
	}
	else  //parent goes down this path (main)
	{
		int wc = wait(NULL);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
	}
	
	return 0;
} 
