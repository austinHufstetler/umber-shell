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

#include "umber_shell.h"
#include "print_commands.h"
#include "math_commands.h"
#include "file_commands.h"
#include "directory_commands.h"
#include "process_commands.h"

pid_t shell_pgid;
struct termios shell_tmodes;
int shell_terminal;
int shell_is_interactive;

static char* currentDirectory;
extern char** environ;

int no_reprint_prmpt;


void initialize_shell()
{

  /* See if we are running interactively.  */
  shell_terminal = STDIN_FILENO;
  shell_is_interactive = isatty (shell_terminal);

  if (shell_is_interactive)
    {
      /* Loop until we are in the foreground.  */
      while (tcgetpgrp (shell_terminal) != (shell_pgid = getpgrp ()))
        kill (- shell_pgid, SIGTTIN);

      /* Ignore interactive and job-control signals.  */
      signal (SIGINT, SIG_IGN);
      signal (SIGQUIT, SIG_IGN);
      signal (SIGTSTP, SIG_IGN);
      signal (SIGTTIN, SIG_IGN);
      signal (SIGTTOU, SIG_IGN);
      signal (SIGCHLD, SIG_IGN);

      /* Put ourselves in our own process group.  */
      shell_pgid = getpid ();
      if (setpgid (shell_pgid, shell_pgid) < 0)
        {
          perror ("Couldn't put the shell in its own process group");
          exit (1);
        }

      /* Grab control of the terminal.  */
      tcsetpgrp (shell_terminal, shell_pgid);

      /* Save default terminal attributes for shell.  */
      tcgetattr (shell_terminal, &shell_tmodes);
    }
}

void prompt_shell(){
	// We print the prompt in the form "<user>@<host> <cwd> >"

	//char hostn[1204] = "";
	//gethostname(hostn, sizeof(hostn));
	//printf("%s@%s %s > ", getenv("LOGNAME"), hostn, getcwd(currentDirectory, 1024));
	printf("%s -> %s -> ", getenv("LOGNAME"), getcwd(currentDirectory, 1024));
}

/* moved to print_commands.c 

void print_line(char* lines[], int n){
	
	int i;
	for(i=1; i<n; i++){
		//printf("%s ", lines[i]);
		write(STDIN_FILENO, lines[i], strlen(lines[i]));
		write(STDIN_FILENO, " ", 1);
	}
	write(STDIN_FILENO, "\n", 1);
}
*/

void handle_command(char* command[], int size){

	if(strcmp(command[0], "print") == 0){
		handle_print_command(command, size);
	}
	else if(strcmp(command[0], "math") == 0){
		handle_math_command(command, size);
	}
	else if(strcmp(command[0], "file") == 0){
		handle_file_command(command, size);
	}
	else if(strcmp(command[0], "directory") == 0){
		handle_directory_command(command, size);
	}
	else if(strcmp(command[0], "process") == 0){
		handle_process_command(command, size);
	}


}


void welcome(){
        printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("\n");
        printf("\t               Umber Shell                    \n");
        printf("\n");
        printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("\n\n");
}

int main(int argc, char *argv[], char ** envp){

	char line[50]; // buffer for the user input
	char* tokens[5];
		
	no_reprint_prmpt = 0; 	// to prevent the printing of the shell
							// after certain methods
	shell_pgid = -10; // we initialize pid to an pid that is not possible
	
	// We call the method of initialization and the welcome screen
	initialize_shell();
	welcome();

    
    // We set our extern char** environ to the environment, so that
    // we can treat it later in other methods
	environ = envp;
	
	// We set shell=<pathname>/simple-c-shell as an environment variable for
	// the child
	setenv("shell",getcwd(currentDirectory, 1024),1);

	while(1){
		if (no_reprint_prmpt == 0)
			prompt_shell();

		no_reprint_prmpt = 0;
		memset( line, '\0', 20);
		fgets(line, 50, stdin);


		// If nothing is written, the loop is executed again
		if((tokens[0] = strtok(line," \n\t")) == NULL) continue;

		if(strcmp(tokens[0],"bye") == 0){
			puts("exiting...");
			return 0;
		}
		
		// We read all the tokens of the input and pass it to our
		// commandHandler as the argument
		int numTokens = 1;
		while((tokens[numTokens++] = strtok(NULL, " \n\t")) != NULL);



		handle_command(tokens, numTokens - 1);
		
		

	}
	return 0;
}
