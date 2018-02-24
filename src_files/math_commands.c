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

#include "math_commands.h"

void handle_math_command(char* lines[], int n){
	
	if(strcmp(lines[1], "add") == 0){
		printf("%d\n",add(atoi(lines[2]), atoi(lines[3])));
	}
	if(strcmp(lines[1], "subtract") == 0){
		printf("%d\n",subtract(atoi(lines[2]), atoi(lines[3])));
	}
	
}

int add(int a, int b){

   int c = 0;

   asm("movl %2, %%eax\n\t"
            "addl %1, %%eax\n\t"
            "movl %%eax, %0\n\t"
            :"=r"(c)
            :"r"(a),"r"(b)
            :"%eax"
      );

   return c;	
}

int subtract(int a, int b){

   int c = 0;

   asm("movl %2, %%eax\n\t"
            "subl %1, %%eax\n\t"
            "movl %%eax, %0\n\t"
            :"=r"(c)
            :"r"(b),"r"(a)
            :"%eax"
      );

   return c;	
}
