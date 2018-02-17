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
