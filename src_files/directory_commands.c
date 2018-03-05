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


//for mkdir
//for more info on mkdir
//https://techoverflow.net/2013/04/05/how-to-use-mkdir-from-sysstat-h/
#include <sys/stat.h>


#include "directory_commands.h"
#include "umber_utils.h"


void handle_directory_command(char* lines[], int n){
	
	if(strcmp(lines[1], "new") == 0){
		create_new_directory(lines[2], lines[3]);
	}
	else if(strcmp(lines[1], "change") == 0){
		change_directory(lines[2]);
	}
	
}

void create_new_directory(char* name, char* permission){
	if(strcmp(permission, "private") == 0){
		int dir = mkdir(name, S_IRUSR | S_IWUSR);
		printf("Directory %s has been created with Read-Write permissions to you only\n",name);
	}
	else if(strcmp(permission, "public") == 0){
		int dir = mkdir(name, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
		printf("Directory %s has been created with public permissions\n",name);
	}
}

void change_directory(char* directory){
	chdir(directory);
}
