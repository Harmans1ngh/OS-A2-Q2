
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>

int main(int argc, char *argv[]){

	if(argc == 3){
		
		int fd[2]; //used to store 2 ends of the pipe
		pid_t child;
		char buff[1500];
		int counter;

		pipe(fd)

		//stores file names in a variable
		int inputFile = open(argv[1], 0);
		int copyFile = open(argv[2], 0666);

		if(inputFile == -1 || copyFile == -1){
			printf("Failed to open file");
			exit(1);
		}
		child=fork();

		if(child == 0){
			close(fd[1]);
			read(fd[0], buff, sizeof(buff));

			write(copyFile, buff, strlen(buff));
		}else{
			close(fd[0]);

			while((counter=read(inputFile, buffm sizeof(buff))>0)){
				write(fd[1], buff, sizeof(buff));
			}
			close(fd[1]);
		}
	}else{
		printf("PLease Input a file name and a name for the copied file when executing!");
		return 0;
	}
}