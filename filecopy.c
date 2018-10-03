/*
Assignment 2: Question #2
Bikramjit Garcha (991330905)
Harmanjeet Singh (991439186)
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char *argv[]){

	if(argc == 3){
		
		int fd[2]; //used to store 2 ends of the pipe
		pid_t child;
		char buff[1500];
		int counter;

		pipe(fd);

		//stores and opens file name into a variable
		int inputFile = open(argv[1], 0);
		int copyFile = open(argv[2], 0666);

		// errorchecking to see if both files have opned
		if(inputFile == -1 || copyFile == -1){
			printf("Failed to open file");
			exit(1);
		}

		//child process 
		child=fork();

		if(child == 0){
			close(fd[1]);
			read(fd[0], buff, sizeof(buff));
			
			//writing to the copyFIle
			write(copyFile, buff, strlen(buff));
		}else{
			close(fd[0]);
			
			// read from file
			while((counter=read(inputFile, buff, sizeof(buff))>0)){
				write(fd[1], buff, sizeof(buff));
			}

			// close and exit 
			close(fd[1]);
		}
	}else{
		printf("PLease Input a file name and a name for the copied file when executing!");
		return 0;
	}
}
