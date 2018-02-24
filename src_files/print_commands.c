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