#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h> 
#include <ctype.h>


#define NUM 10        // the command number
#define MAX_OPEN 10  //  limits max of 10 open files
#define MAX_ARGS 64  // limits number of args
#define SEPARATORS " \t\n"  // token sparators
#define PATH 100 //  limits the length of file
#define BUFFER 1024  // limits line buffer

extern char **environ;   // environment array established
void clear(void);//clears the screen
int echo(char **args,const Redirect *Inputs,int *states);// Runs echo command 
int environment(void);// runs the environment command
void pause(int n); //pauses until user clicks [ENTER]
int help(char **args,const Redirect *Outputs,int *states);// displays help
int cd(char **args,const Redirect *Inputs, int *states);// Runs cd command 
int dir(char **args,const Redirect *Inputs, int *states);// Runs dir command  
