#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{ int child_pid;
 child_pid = fork(); /* Tao tien trinh con*/
 if (child_pid > 0){
 printf(" Day la tien trinh cha. Ngu 1 phut. Dang sleep\n");
 sleep(60);
 }
 else exit(0); /* Day la tien trinh con. Ket thuc*/
 return 0;
}
