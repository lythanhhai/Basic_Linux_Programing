#include <pthread.h>
#include <stdio.h>

struct char_print_parms
{
	char character; // ký tự để in
	int count; // số lần in
};

void* char_print(void* parameters)
{
	 struct char_print_parms* p = (struct char_print_parms*) parameters;
	 int i = 0;
	 for(i = 0 ; i < p->count ; i++)
	 {
	 	fputc(p->character, stderr);
	 }
	 printf("\n");
	 return NULL;
}

int main()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	
	struct char_print_parms thread1_args; 
	struct char_print_parms thread2_args;
	
	thread1_args.character = 'x';
	thread1_args.count = 30000;
	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	
	thread2_args.character = 'o';
	thread2_args.count = 20000;
	pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
	
	// luồng main chờ 2 luồng phụ
	/* Muốn chắc chắn thread1 và thread2 kết thúc*/
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);
	
	return 0;
}

