#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

	void sigint_handler(int sig)
	{
		printf("This is a special signal handler for INT signal\n");
	}

	void sigquit_handler(int sig)
	{
		printf("This is a special signal handler for SIGQUIT signal\n");
	}

	void sigstp_handler(int sig)
	{
		printf("This is a special signal handler for TSTP signal\n");
	}
}
