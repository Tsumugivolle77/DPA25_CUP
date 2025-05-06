#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <limits.h>

#define NUM_RUNS 4
#define N (1ll << 26)

double monte_carlo_pi(long long n);

int main(int argc, char **argv)
{
    int nc = argc;
    int *conf = malloc(sizeof(int) * nc);
    conf[0] = 1;
    for (int i = 1; i < argc; i++)
    {
        conf[i] = atoi(argv[i]);
    }

    double *times = malloc(sizeof(double) * nc);

    printf("Using n=%lld random points\n", N);
    printf("%3s, %6s, %6s, %7s, %7s\n", "P", "T", "S_rel", "pi", "error");

    // for each number of threads
    for (int i = 0; i < nc; i++)
    {
        int nt = conf[i];

        omp_set_num_threads(nt);

        double pi = 0.0;

        for (int r = 0; r < NUM_RUNS; r++)
        {
            double t0 = omp_get_wtime();
            pi = monte_carlo_pi(N);
            double t1 = omp_get_wtime();

            double elapsed = t1 - t0;
            if (r == 0 || elapsed < times[i])
                times[i] = elapsed;
        }

        printf("%3d, %6.3lf, %6.3lf, %7.5lf, %7.5lf\n",
               conf[i], times[i], times[0] / times[i], pi, fabs(M_PI - pi));
    }

    free(conf);
    free(times);

    return 0;
}

#include "your_code.c"