#include <stdio.h>
#include <string.h>
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
	printf("?>");
	scanf("%s", str);
	printf("\n You entered: %s ", str);
	char* input = strtok(str, " ");
	printf("\n Your command is %s " , input);
}
