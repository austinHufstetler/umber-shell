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
	
}

int get_process_id(){
	return (int)getpid();
}
