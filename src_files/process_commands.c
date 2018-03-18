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
	
	if(strcmp(lines[1], "get") == 0){
		if(strcmp(lines[2], "id") == 0) {
			printf("%d\n",get_process_id());
		}
	}
	else if(strcmp(lines[1], "replace") == 0){
		replace_process(lines[2], lines, n);
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
