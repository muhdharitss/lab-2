#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void	name()
{
	char name[100];
	printf("\nPlease enter thy name: ");
	fgets(name, sizeof(name), stdin);
	printf("\nHello there, ");
	puts(name);
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			printf("Child process %d with ID %d says... ", i + 1, getpid());
			name();	
			exit(0);
		}
		else
			wait(NULL);
	}
	printf("Job is done\n");
	return EXIT_SUCCESS;
}
