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
#include <errno.h>

#include "file_commands.h"

void handle_file_command(char* lines[], int n){
	
	if(strcmp(lines[1], "new") == 0){
		create_new_file(lines[2], lines[3]);
	}
	if(strcmp(lines[1], "rename") == 0){
		rename_file(lines[2], lines[3]);
	}
	if(strcmp(lines[1], "move") == 0){
		move_file(lines[2], lines[3]);
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

void rename_file(char* current_name, char* new_name){
	int check = rename(current_name, new_name);
	if(check == 0){
		printf("\nSuccessfully changed name of file %s to %s\n", current_name, new_name);
	}
	else if(errno == 2){
		printf("Error Code (errno) 2: File %s does not exist\n", current_name);
	}
	else{
		printf("\nThere was an error with renaming your file\n");
	}
}

void move_file(char* file_name, char* destination){

	char file_and_destination[100];
	strcpy(file_and_destination, destination);
	strcat(file_and_destination, file_name);
	int check = rename(file_name, file_and_destination);
	if(check == 0){
		printf("Successfully moved file %s to %s directory\n", file_name, destination);
	}
	else if(errno == 2){
		printf("Error Code (errno) 2: File %s or directory %s does not exist\n", file_name, destination);
	}
	else{
		printf("\nThere was an error with moving your file\n");
	}
}