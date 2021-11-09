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
	pthread_t thread;
	int n;
	int prime;
	printf("\nNhap n:"); scanf("%d",&n);
	/* Bắt đầu luồng tính toán số nguyên tố thứ n. */
	pthread_create (&thread, NULL, &compute_prime, &n);
	/* Thực hiện vài việc ở đây... */
	/* Chờ luồng tính số nguyên tố hoàn thành, và
	lấy kết quả trả về.*/
	//pthread_join (thread, (void*) &prime);
	pthread_t tid = pthread_self();
	printf("In function thread id = %d\n", (int)tid);
	if (!pthread_equal(pthread_self(), thread))
 		pthread_join(thread, (void*)&prime);
	/* In ra số nguyên tố thứ n. */
	printf("So nguyen to thu %d la %d.\n", n, prime);
	return 0;
}
