#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

	void sigint_handler(int sig);
	void sigstp_handler(int sig);
	void sigquit_handler(int sig);
	char s[200];

	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	else if (signal(SIGQUIT, sigquit_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	else if (signal(SIGSTOP, sigstp_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	printf("Enter a string:\n");
	if (fgets(s, 200, stdin) == NULL)
		perror("gets");
	else
		printf("You entered:%s\n", s);
	return 0;
}

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
