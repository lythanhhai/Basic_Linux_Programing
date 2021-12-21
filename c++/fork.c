#include <stdio.h>
#include <unistd.h>

int main()
{
	int child_pid;
	printf("Chuong trinh co id cua tien trinh la: %d!\n", (int) getpid());
	child_pid = fork();
	if(child_pid < 0)
	{
		printf("loi khoi tai cua tien trinh con \n");
	}
	else if(child_pid > 0)
	{
		printf("Day la tien trinh cha , voi ID la %d!\n", (int) getpid());
		printf("ID cua tien trinh con la %d!\n", child_pid);
		sleep(5);
	}
	else 
	{
		printf("Day la tien trinh con, voi id la %d %d!\n", (int) getpid(), child_pid);
	}
	printf("\n\n");
	return 0;
}
