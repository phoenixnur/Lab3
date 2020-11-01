#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

	void sigint_handler(int sig);


	if(signal(SIGINT,  sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

        int a=1;
        int isprime=0;
        int p[2];
       	int  pipe(p);

        int pid = fork();
        if(pid < 0)
                exit(1);
        if(pid == 0)
        {
                close(p[1]);
                fread(p[0],&a,sizeof(int));
                isprime = 1;
                for(int i=2;i*i<=a;i++)
                        if(a%i==0)
                                isprime = 0;
                if(isprime == 1)
                        printf("%d is prime",a);
                close(p[0]);
        }
        else
        {
                close(p[0]);
                while(a!=0){
                        printf("Please enter an integer number:");
                        scanf("%d",&a);
                        fwrite(p[1],&a,sizeof(int));
                }
                wait(0);
               	pclose(p[1]);

        }

        return 0;
}
