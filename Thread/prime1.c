#include <pthread.h>
#include <stdio.h>
#include <math.h>

/*Hàm tính toán trả về số nguyên tố thứ n, n là là giá trị được trỏ bởi *arg. */
void* compute_prime (void* arg)
{
	 int pri = 2;
	 int n = *((int*) arg);
	 while (1)
	 {
		 int i;
		 int nguyento = 1;
		 for ( i = 2; i < pri / 2; ++i)
		 {
			 if (pri % i == 0)
			 {
				 nguyento = 0;
				 break;
			 }
		 }
		 if (nguyento)
		 {
		 	if (--n == 0) return (void*) pri;
	 	 }
	 	 ++pri;
	}
	return NULL;
}
int main ()
{
	int m;//số luồng
	printf("\nNhap m:"); scanf("%d",&m);
	pthread_t threads[m];
	int prime[m];
	for(int i = 0; i < m ; i++)
	{
		pthread_create (&threads[i], NULL, &compute_prime, &i);
	}
	/* Chờ luồng tính số nguyên tố hoàn thành, và
	lấy kết quả trả về.*/
	for(int i = 0; i < m ; i++)
	{
		if (!pthread_equal(pthread_self(), threads[i]))
 		pthread_join(threads[i], (void*)&prime[i]);
	}
	for(int i = 0; i < m ; i++)
	{
		printf("So nguyen to thu %d la %d.\n", i + 1, prime[i]);
	}
	
	return 0;
}
