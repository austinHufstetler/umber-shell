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

#include "file_commands.h"

void handle_file_command(char* lines[], int n){
	
	if(strcmp(lines[1], "new") == 0){
		create_new_file(lines[2], lines[3]);
	}
	
}

void create_new_file(char* name, char* permission){
	if(strcmp(permission, "private") == 0){
		int file = open(name, O_CREAT, S_IRUSR | S_IWUSR);
		printf("File %s has been created with Read-Write permissions to you only\n",name);
		close(file);
	}
	else if(strcmp(permission, "none") == 0){
		int file = open(name, O_CREAT);
		printf("File %s has been created with no permissions\n",name);
		close(file);
	}
}
