#include <stdio.h>

//Commands yet to be created down below
void clrKyb(void){
	char c = 0;
	while((c = getchar()) != '\n' && c != EOF) {};
}

//TODO CD <directory - Change directory, if there is no <directory> augment present, print current directory
void change_dir(char* input){
	printf("\nchange directory");
	return;
}

void clear(){
	printf("\033[2J");
	printf ("\033c");
	printf("\nscreen cleared");
	return;
}
//Untested dir <directory> - List contents of <directory>
void dir(char* input){
	printf("\ndirectory:\n");
	for i in $(ls -d */): do echo ${i%%/}; done
	return;
}
//TODO environ - list all environment strings

void environ(char* input){
	printf("\nenviron");
	return;
}

//TODO echo <comment> - display <comment> on the display followed by a new line

void echo(char* input){
	printf("\n");
	return;
}


//TODO help - display user manual using the more filter

void help(char* input){
	printf "%s" "$(<help.txt)";
	return;
}


//TODO pause - pause operation of the shell until 'enter' is pressed

void pause(char* input){
	printf("Session Paused, Press [ENTER] to continue");
	char enter = 0;
	clrKyb();
	return;
}

//TODO shell envireonment should contain shell=<pathname>/myshell where <pathname>/myshell is the full path for the shell executable (not hardwired, the one from where it was executed)

//TODO all other input is interpreted as program invocation, the shell should fork and exec the programs as its own child processes.

//TODO shell must be able to take its command line input from a file, if "fillshell batchfile" is ran it will assume the file contains a set of command lines for the shell to process, when end of file is reached the shell should exit

//TODO shell must support background execution of programs, an "&" at the end of a command indicates that the shell should return the command line prompt immediately after launching that program
