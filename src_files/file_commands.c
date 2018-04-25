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
#include <strings.h>


#include "file_commands.h"

void handle_file_command(char* lines[], int n){
	
	if(n >= 2){
		if(strcmp(lines[1], "new") == 0){
			if(n == 4){
				create_new_file(lines[2], lines[3]);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }
		}
		else if(strcmp(lines[1], "rename") == 0){
			if(n == 4){
				rename_file(lines[2], lines[3]);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }
		}
		else if(strcmp(lines[1], "move") == 0){
			if(n == 4){
				move_file(lines[2], lines[3]);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }
		}
		else if(strcmp(lines[1], "delete") == 0){
			if(n == 3){
				delete_file(lines[2]);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }
		}
		else if(strcmp(lines[1], "copy") == 0){
			if(n == 4){
				copy_file(lines[2], lines[3]);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }
		}
		else if(strcmp(lines[1], "write") == 0){
			if(n >= 3){
				write_to_file(lines[2], n, lines);
			}
	        else{
	            printf("\nWrong number of arguments \n\n");
	        }			
		}
		else if(strcmp(lines[1], "help") == 0){
			file_help();
		}
		else{
	      printf("\nCommand does not exist \n\n");
		}
	}
	else{
		printf("\nYou only entered a category, please enter a command \n\n");
	}
	
}

void create_new_file(char* name, char* permission){
	if(strcmp(permission, "private") == 0){
		int file = open(name, O_CREAT, S_IRUSR | S_IWUSR);
		printf("File %s has been created with Read-Write permissions to you only\n",name);
		close(file);
	}
	else if(strcmp(permission, "public") == 0){
		int file = open(name, O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
		printf("File %s has been created with Read-Write permissions to everyone\n",name);
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
		printf("\nError Code (errno) %d: There was an error with renaming your file\n", errno);
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
		printf("\nError Code (errno) %d: There was an error with moving your file\n", errno);
	}
}

void delete_file(char* file_name){

	int check = unlink(file_name);
	if(check == 0){
		printf("Successfully deleted file %s\n", file_name);
	}
	else if(errno == 2){
		printf("Error Code (errno) 2: File %s does not exist\n", file_name);
	}
	else{
		printf("\nError Code (errno) %d: There was an error with deleting your file\n", errno);
	}



}

void copy_file(char* file_name, char* location){

	if(strcmp(file_name, location) == 0){
		printf("Error, this will overwrite your file \n");
		return;
	}

	int* buffer[1];

	//without system calls

	/*
	FILE* source;
	FILE* destination;
	int c;

	if((source = fopen(file_name, "r")) && (destination = fopen(location, "w"))){
		while((c = getc(source)) != EOF){
			putc(c, destination);
		}
		fclose(source);
		fclose(destination);
		printf("Successfully copied file %s to %s\n", file_name, location);
	}
	else{
		printf("There was an error copying file %s\n", file_name);
	} */

	int source ;
	int destination;

	if(((source = open(file_name, O_RDONLY)) == -1) || ((destination = open(location, O_CREAT | O_WRONLY, 0666)) == -1)){
		printf("Error, there was an error copying your file \n");
	}
	else{



	    while ((read(source, buffer, 1)) != 0)
	    {
	        write(destination, buffer, 1);
	        bzero(buffer, 1);
	    }

	    close(source);
	    close(destination);
	}


}

void write_to_file(char* destination, int n, char* lines[]){
	int file;
	if((file= open(destination, O_WRONLY)) == -1){
		printf("Error, there was an error copying your file \n");
	}
	else{
		int i;
		for(i=3; i<n; i++){
			//printf("%s ", lines[i]);
			write(file, lines[i], strlen(lines[i]));
			write(file, " ", 1);
		}
		printf("You have Successfully written to the file \n");
		close(file);
	}

}

void file_help(){
     printf("\nfile new foo.fee public - creates a new file named foo.fee in current folder and gives read, write, execute rights to every user") ; 
     printf("\nfile new foo.fee private - creates a new file named foo.fee in current folder and gives read, write rights to current user only") ; 
     printf("\nfile new foo.fee none - creates a new file named foo.fee in current folder and gives read, write rights to no one :) (not very useful, but interesting to see how to do it)") ; 
	 printf("\nfile rename current_name new_name - renames a file") ; 
     printf("\nfile move file_name directory_name - moves a file from current directory to new directory (example. file move test.txt test/)") ; 
     printf("\nfile delete file_name - deletes file called file_name that is in current directory") ; 
     printf("\nfile write file_name foo fee fii - writes whatever comes after file_name to file") ; 
     printf("\n\n");
}



