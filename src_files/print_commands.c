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
#include <dirent.h>

#include "print_commands.h"
#include "umber_utils.h"

void handle_print_command(char* lines[], int n){
	
	if( n >= 2){
		if(strcmp(lines[1], "this") == 0){
			print_line(lines, n);
		}
		else if(strcmp(lines[1], "file") == 0){
			if(n == 3){
				print_text_file(lines[2]);
			}
			else if(n == 4){
				print_text_file_limit_chars(lines[2], atoi(lines[3]));
			}
		}
		else if(strcmp(lines[1], "directory") == 0){
			print_current_directory();
		}
		else if(strcmp(lines[1], "help") == 0){
			print_help();
		}
		else{
	      printf("\nCommand does not exist \n\n");
		}
	}
	else{
		printf("\nYou only entered a category, please enter a command \n\n");
	}
	
}


void print_line(char* lines[], int n){
	
	int i;
	for(i=2; i<n; i++){
		//printf("%s ", lines[i]);
		write(STDIN_FILENO, lines[i], strlen(lines[i]));
		write(STDIN_FILENO, " ", 1);
	}
	write(STDIN_FILENO, "\n", 1);
}

//geeksforgeeks input output system calls c create open close read write
void print_text_file_limit_chars(char* path, int num_chars){
	int fd = open(path, O_RDONLY);
	int size;
	char* c = (char*)calloc(num_chars, sizeof(char));

	if(fd < 0){
		printf("Could not open file\n");
	}
	else{
		size = read(fd, c, num_chars);
		write(STDIN_FILENO, c, size);
	}
	printf("\n");
	
	free(c);
	close(fd);

}

void print_text_file(char* path){
	int fd = open(path, O_RDONLY);
	int size;
	size_t num_chars = get_file_size(path);
	char* c = (char*)calloc(num_chars, sizeof(char));

	if(fd < 0){
		printf("Could not open file\n");
	}
	else{
		size = read(fd, c, num_chars);
		write(STDIN_FILENO, c, size);
	}
	printf("\n");
	
	free(c);
	close(fd);

}

void print_current_directory(){
	DIR *dir;
	dir = opendir(".");
	struct dirent *sd;
	if(dir == NULL){
		printf("\nUnable to open\n");
	}
	else{
		printf("\n%-20s%-5s\n\n", "Name", "Size");
		while((sd=readdir(dir))!=NULL){
			printf("%-20s %-5hu \n", sd->d_name, sd->d_reclen);
		}
		printf("\n");
		closedir(dir);

	}


}

void print_help(){
	printf("\nprint this foo fee fii - prints whatever comes after this statement");
	printf("\nprint file foo.txt x -prints text file on shell with only x number of characters printed");
	printf("\nprint file foo.txt - prints entire text file");
	printf("\nprint directory - prints all files and folders in current directory");
     printf("\n\n");
}
