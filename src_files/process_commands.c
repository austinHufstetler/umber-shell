#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>



#include "process_commands.h"


void handle_process_command(char* lines[], int n){
	
	if(n >= 2){
		if(strcmp(lines[1], "get") == 0){
			if(n == 3){
				if(strcmp(lines[2], "id") == 0) {
					printf("%d\n",get_process_id());
				}
			}
			else{
				printf("\nWrong number of arguments \n\n");
			}
		}
		else if(strcmp(lines[1], "replace") == 0){
			if(n >= 3){
				replace_process(lines[2], lines, n);
			}
			else{
				printf("\nWrong number of arguments \n\n");
			}
		}
		else if(strcmp(lines[1], "help") == 0){
			process_help();
		}
		else{
	      printf("\nCommand does not exist \n\n");
		}
	}
	else{
		printf("\nYou only entered a category, please enter a command \n\n");
	}
	
}

int get_process_id(){
	return (int)getpid();
}

void replace_process(char* path, char* args[], int n){

	//deleting first few arguments from args
	char* args_modified[n - 3];
	for(int i=0; i<n-3; i++){
		args_modified[i] = args[i+3];
	}

	if(execv(path, args_modified) != -1){

	}
	else{
		printf("\n an error has occured");
	}

}

void process_help(){
     printf("\n\n");
}
