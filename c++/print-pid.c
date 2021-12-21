#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("ID cua tien trình la %d!\n", (int) getpid());
	printf("ID cua tien trinh cha la %d!\n", (int) getppid());
	//system("ls -l");
	//system("zenity --error --text \"xin chao\"");
	return 0;
}
