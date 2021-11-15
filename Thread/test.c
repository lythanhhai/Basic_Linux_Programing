#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define M 3
#define P 2
#define n 4
#define m 3
#define p 2


struct v
{
    int i;
    int j;
};

double A[N][M] = {{1.0, 2.0, 4.0}, {3.0, 4.0, 5.0}, {4.0, 5.0, 7.0}, {5.0, 5.0, 7.0}};
double B[M][P] = {{2.0, 3.0}, {4.0, 5.0}, {2.0, 3.0}};
double C[100][100];

static void * multiplication(void *arg){
    struct v *data = (struct v *)arg;
    for(int l=0; l < N; l++)
    {
            printf("l(%d) = %d, %d\t", l, data[l].i, data[l].j);
    }
    printf("\n");
    int l;
    for(l=0; l < N; l++)
    {
        int i=(data[l]).i;
        int j=(data[l]).j;
        double sum=0;
        int d;

        for (d = 0; d < M; d++)
        {
            sum = sum + A[i][d]*B[d][j];
        }

        C[i][j] = sum;
        sum = 0;
    }
    return 0;
}


int main(void)
{	
   
	
    pthread_t threads[n];
    int i, k;

    struct v **data;
    data = (struct v **)malloc(n * sizeof(struct v*));

    for(i = 0; i < N; i++)
    {
        data[i] = (struct v *)malloc(n * sizeof(struct v));

        for(k = 0; k < M; k++)
        {
            data[i][k].i = i;
            data[i][k].j = k;
        }

        pthread_create(&threads[i], NULL, multiplication, data[i]);
    }
    
    for(i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < N; i++)
    {
        for (k = 0; k < P; k++)
        {
            printf("%lf\t", C[i][k]);
        }

        printf("\n");

        free(data[i]);
    }

    free(data);

    return 0;
}
