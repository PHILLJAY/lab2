#include <stdio.h>

int main (int argc, char **argv)
{
    //run infinite loop
    phil_loop();

















    return EXIT_SUCCESS;
}

void phil_loop(void)
{
	char str[100];
	print("P>");
	scanf("%s", str);
	printf("\n You entered: %s ", str);
}
