#include <stdio.h>

//Commands yet to be created down below
//TODO CD <directory - Change directory, if there is no <directory> augment present, print current directory

void change_dir(char* input){
	printf("change directory");
	return;
}
//TODO clr - clear screen
void clear(char* input){
	printf("screen clear");
	return;
}
//TODO dir <directory> - List contents of <directory>
void directory (char* input){
	printf("directory");
	return;
}
//TODO environ - list all envireonment strings

//TODO echo <comment> - display <comment> on the display followed by a new line
//TODO help - display user manual using the more filter
//TODO pause - pause operation of the shell until 'enter' is pressed
//TODO quit - quit the shell
//TODO shell envireonment should contain shell=<pathname>/myshell where <pathname>/myshell is the full path for the shell executable (not hardwired, the one from where it was executed)
//TODO all other input is interpreted as program invocation, the shell should fork and exec the programs as its own child processes.
//TODO shell must be able to take its command line input from a file, if "fillshell batchfile" is ran it will assume the file contains a set of command lines for the shell to process, when end of file is reached the shell should exit
//TODO shell must support background execution of programs, an "&" at the end of a command indicates that the shell should return the command line prompt immediately after launching that program
