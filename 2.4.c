#include <stdio.h> include <stdlib.h> include <sys/types.h> include <sys/wait.h> 
#include <unistd.h>
int h; char names[20]; void inputNAME(){
	printf("Child process no. %d\nPID=%d\nEnter the process name: ", h, 
getpid());
	scanf("%s", names);
}
void outputNAME(){
	printf("\nChild process %d: %s\n", h, names);
}
int main(void){
	for(h = 1; h <= 4; h++){
		pid_t pid = fork();
		if(pid == 0){
			inputNAME();
			outputNAME();
			exit(0);
		}
		else{
			printf("\nIn progress...\n");
			wait(NULL);
		}
	}
	printf("\nJOB IS DONE\n");
	return EXIT_SUCCESS;
}
