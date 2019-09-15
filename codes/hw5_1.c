#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, int *argv[])
{
	int x = 100;
	printf("hello world, I am parent process. (PID:%d)", (int)getpid());
	int child_PID = fork();
	if(child_PID < 0)
	{
		fprintf(stderr, "fork failed\n");
        exit(1);
	}
	else if(child_PID == 0)
	{
		printf("I am child(PID:%d), ", child_PID);
		printf("and x = %d\n", --x);
	}
	else
	{
		printf("I am parent(PID:%d) of child(PID:%d), ", (int)getpid(), child_PID);
		printf("and x = %d\n", ++x);
	}
	
	return 0;
}
