#include <stdio.h>

int main(int argc, char * argv[])
{
	
	printf("hello, you are still learning C!\n");
	printf("number of argument to the main function: %d\n", argc);
	for(int i = 0 ; i < argc ; i++)
	{
		printf("Argument number %d is %s\n", i, argv[i]);
	}
	return 0;
}

