#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utility.h"

int main (int argc, char **argv)
{
    //run infinite loop
    fill_loop();
//    return EXIT_SUCCESS;
}

void fill_loop(void)
{
	//here is the main code, it takes whatever input you give it and stores it in str.
	//TODO:	decide on command names
	//TODO:	create a switch that recognizes them
	//TODO: in utility.c create the functions.
	
	char str[100];
	while(true){
		printf("\n?>");
		scanf("%s", str);
		printf("\n You entered: %s ", str);
		char* input = strtok(str, " ");
		//printf("\n Your command is %s " , input);
		if(strcmp(input, "cd") == 0){
		change_dir(input);	
		} else if (strcmp(input, "clr") == 0){
			clear();
		} else if (strcmp(input, "dir") == 0){
			dir(input);	
		} else if (strcmp(input, "environ") == 0){
			environ(input);
		} else if (strcmp(input, "echo") == 0){
			echo(input);	
		} else if (strcmp(input, "help") == 0){
			help(input);	
		} else if (strcmp(input, "pause") == 0){
			pause(input);
		} else if (strcmp(input, "quit") == 0){
			quit(input);
			break;
		} else{
			printf("I dont know that command");
		}
	}
}
