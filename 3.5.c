#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int main (void) {
	void sigint_handler(int sig);
	int fd[2],temp,prime,flag = 0;
	pid_t pid = fork();
	pipe(fd);
	int a;
	
	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	if(pid == 0) {
		int a;
		printf("Please enter an integer number:\n");
		scanf("%d", &a);
		write(fd[1],&a,sizeof(int));
	}

	else if (pid >0) {
		wait(NULL);
		read(fd[0],&a,sizeof(int));
		prime = a /2;
	
		for(int i=2; i<=prime; i++) {
			if(prime % i == 0) {
				flag =1;
				break;
			}
		}
		if (flag == 0) {
			printf ("%d is a Prime Number\n");
		}
		else {
			printf ("%d is not a Prime Number\n");
		}
		return 0;
	}	
	else {
		printf("Error");
		exit(1);
	}
}

	void sigint_handler(int sig)
	{
		printf("Terminate!\n");
	}
