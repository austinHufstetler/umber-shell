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
	
   if(n >= 2){
   	if(strcmp(lines[1], "add") == 0){
         if(n == 4){
   		 printf("%d\n",add(atoi(lines[2]), atoi(lines[3])));
         }
         else{
            printf("\nWrong number of arguments \n\n");
         }
   	}
   	else if(strcmp(lines[1], "subtract") == 0){
         if(n == 4){
            printf("%d\n",subtract(atoi(lines[2]), atoi(lines[3])));
         }
         else{
            printf("\nWrong number of arguments \n\n");
         }
   	}
     else if(strcmp(lines[1], "multiply") == 0){
         if(n == 4){
            printf("%d\n",multiply(atoi(lines[2]), atoi(lines[3])));
         }
         else{
            printf("\nWrong number of arguments \n\n");
         }

      }
     else if(strcmp(lines[1], "divide") == 0){
         if(n == 4){
            printf("%d\n",divide(atoi(lines[2]), atoi(lines[3])));
         }
         else{
            printf("\nWrong number of arguments \n\n");
         }
      }
     else if(strcmp(lines[1], "mod") == 0){
         if(n == 4){
            printf("%d\n",mod(atoi(lines[2]), atoi(lines[3])));
         }
         else{
            printf("\nWrong number of arguments \n\n");
         }
      }
      else if(strcmp(lines[1], "help") == 0){
         math_help();
      }
      else{
         printf("\nCommand does not exist \n\n");
      }
   }
   else{
      printf("\nYou only entered a category, please enter a command \n\n");
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

int multiply(int a, int b){

   int c = 0;

   asm("movl %2, %%eax\n\t"
            "imul %1, %%eax\n\t"
            "movl %%eax, %0\n\t"
            :"=r"(c)
            :"r"(b),"r"(a)
            :"%eax"
      );

   return c;   
}


int divide(int a, int b){

   int c = 0;
   int d = 0;

   
   asm("movl $0x0, %%edx;"
            "movl %2, %%eax;"
            "movl %3, %%ebx;"
            "idivl %%ebx;" 
            : "=a" (c), "=d" (d) 
            : "g" (a), "g" (b)
      );

   return c;   
}

int mod(int a, int b){

   int c = 0;
   int d = 0;

   asm("movl $0x0, %%edx;"
            "movl %2, %%eax;"
            "movl %3, %%ebx;"
            "idivl %%ebx;" 
            : "=a" (c), "=d" (d) 
            : "g" (a), "g" (b)
      );

   return d;   
}

void math_help(){
     printf("\n\n");
}
