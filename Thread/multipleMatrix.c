#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int m, n, k;
double A[100][100];
double B[100][100];
double C[100][100];
struct v
{
    int i;
    int j;
};

void nhapA(double A[][100], int m, int n)
{
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			printf("nhap A[%d][%d] = \n",i, j);
			scanf("%lf", &A[i][j]);
		}
	}
}

void nhapB(double B[][100], int n, int k)
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < k ; j++)
		{
			printf("nhap B[%d][%d] = \n",i, j);
			scanf("%lf", &B[i][j]);
		}
	}
}

void * multiple(void *arg){
    struct v *data = (struct v *)arg;
    int l;
    for(l=0; l < k; l++)
    {
        printf("l(%d) = %d, %d\t", l, data[l].i, data[l].j);
    }
    printf("\n");
    //int l;
    for(l=0; l < k; l++)
    {
        int i=(data[l]).i;
        int j=(data[l]).j;
        double sum=0;
        size_t d;

        for (d = 0; d < n; d++)
        {
            sum = sum + A[i][d]*B[d][j];
        }

        C[i][j] = sum;
        sum = 0;
    }
    return 0;
}

void main()
{
	printf("nhap m = ");
	scanf("%d", &m);
	printf("nhap n = ");
	scanf("%d", &n);
	printf("nhap k = ");
	scanf("%d", &k);

	nhapA(A, m, n);
	nhapB(B, n, k);
	
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			printf("A[%d][%d] = %lf\t",i, j, A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < k ; j++)
		{
			printf("B[%d][%d] = %lf\t",i, j, B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	pthread_t threads[m];
	int i, j;

	struct v **data;
	data = (struct v **)malloc(m * sizeof(struct v*));
	
	for(i = 0; i < m; i++)
	{
		data[i] = (struct v *)malloc(k * sizeof(struct v));

		for(j = 0; j < k; j++)
		{
		    data[i][j].i = i;
		    data[i][j].j = j;
		}
		pthread_create(&threads[i], NULL, multiple, data[i]);
	}

	for(i = 0; i < m; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	// in kết quả
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < k; j++)
		{
		    printf("%lf\t", C[i][j]);
		}

		printf("\n");
		free(data[i]);
	}

	free(data);
}
