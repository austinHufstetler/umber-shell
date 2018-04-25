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


//for mkdir
//for more info on mkdir
//https://techoverflow.net/2013/04/05/how-to-use-mkdir-from-sysstat-h/
#include <sys/stat.h>


#include "directory_commands.h"
#include "umber_utils.h"


void handle_directory_command(char* lines[], int n){
	
	if(n >= 2){
		if(strcmp(lines[1], "new") == 0){
			if(n == 4){
				create_new_directory(lines[2], lines[3]);
			}
			else{
				printf("\nWrong number of arguments \n\n");
			}
		}
		else if(strcmp(lines[1], "change") == 0){
			if(n == 3){
				change_directory(lines[2]);
			}
			else{
				printf("\nWrong number of arguments \n\n");
			}
		}
		else if(strcmp(lines[1], "delete") == 0){
			if(n == 4){
				if(strcmp(lines[2], "empty") == 0){
					delete_empty_directory(lines[3]);
				}
			}
			else{
				printf("\nWrong number of arguments \n\n");
			}
		}
		else if(strcmp(lines[1], "help") == 0){
			directory_help();
		}
		else{
	      printf("\nCommand does not exist \n\n");
		}
	}
	else{
		printf("\nYou only entered a category, please enter a command \n\n");
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

void delete_empty_directory(char* directory_name){

	int check = rmdir(directory_name);
	if(check == 0){
		printf("Successfully deleted directory %s\n", directory_name);
	}
	else if(errno == 2){
		printf("Error Code (errno) 2: Directory %s does not exist\n", directory_name);
	}
	else if(errno == 39){
		printf("Error Code (errno) 39: Directory %s is not empty\n", directory_name);
	}
	else{
		printf("\nError Code (errno) %d: There was an error with deleting your directory\n",errno);
	}

}

void directory_help(){
     printf("\ndirectory new foo public - creates a new directory named foo in current folder and gives read, write, execute rights to every user") ; 
     printf("\ndirectory new foo private - creates a new directory named foo in current folder and gives read, write rights to current user only") ; 
     printf("\ndirectory change path - changes directory to path name") ; 
	 printf("\ndirectory delete empty directory_name - deletes empty(important) directory called directory_name") ; 
     printf("\n\n");
}

