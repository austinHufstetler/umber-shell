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

#include "print_commands.h"

void handle_print_command(char* lines[], int n){
	
	if(strcmp(lines[1], "this") == 0){
		print_line(lines, n);
	}
	else if(strcmp(lines[1], "file") == 0){
		print_text_file(lines[2], atoi(lines[3]));
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
void print_text_file(char* path, int num_chars){
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