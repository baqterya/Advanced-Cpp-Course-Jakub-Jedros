#include <stdio.h>
#include <time.h>
#include <omp.h>

int main() {
    const int N = 1000000000;
    int i = 0;
    double sum = 0;
    clock_t t0 = clock();
    
    double start, end;
    start = omp_get_wtime();

    #pragma omp parallel for private(i) reduction(+:sum)
        for (i = N-1; i >= 0; --i)
        {
            sum += 1.0/(i+1.0);
        }

    clock_t t1 = clock();
    end = omp_get_wtime();

    printf("s = %g\n", sum);
    printf("clock_t t = %g\n", ((double)t1 - t0)/CLOCKS_PER_SEC);   
    printf("omp_get_wtime t = %g\n", end - start);    
}