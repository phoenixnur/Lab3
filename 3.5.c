#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int main (void) 
{

	void sigint_handler(int sig);
        
	int prime, flag, temp, ppfds[2] =0;
	pipe(ppfds);
        pid_t pid = fork();
	
	if(signal(SIGINT, sigint_handler) == SIG_ERR) 
	{
		perror("signal");
		exit(1);
	}
        
        if(pid == 0)
	{
		int num;
		printf("Enter an integer number:\n");
		scanf("%d",&num);
		write(ppfds[1],&num,sizeof(num));
	}
	else if(pid >0) 
	{
		wait(NULL);
		printf("This is a Parent Process!\n");
		read(ppfds[0],&temp,sizeof(temp));
		prime = temp / 2;

		for(int i=2; i<=prime; i++) 
		{
			if(prime % i == 0) 
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0) 
		{
			printf("\n is a Prime Number\n", temp);
		}
		else 
		{
			printf("\n is not a Prime Number\n", temp);
		}
		return 0;
	}
	else 
	{
		printf("\nInvalid Value: %d", getpid());
		exit(1);
	}
}

void sigint_handler(int sig) 
{
	printf("Terminate!");
}

