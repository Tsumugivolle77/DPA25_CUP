#include <_stdlib.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
    Here you should write your parallel implementation of
    the Monte Carlo method to estimate the value of pi.
    The output of this function should be the ratio between
    n and m, as described in the exercise sheet (4m/n).

    Feel free to have a look inside the main.c file to
    understand what is going on. However, you should only
    hand in this file.
*/

double monte_carlo_pi(long long n)
{
    int m = 0;
#pragma omp parallel
    {
        unsigned short seed[3];
        // unsigned int seed = time(NULL) ^ omp_get_thread_num();
        // struct drand48_data rand_buffer;
        long t = time(NULL);
        seed[0] = (unsigned short)(t & 0xFFFF);
        seed[1] = (unsigned short)((t >> 16) & 0xFFFF);
        seed[2] = (unsigned short)(omp_get_thread_num() & 0xFFFF); 
        // srand48(time(NULL) ^ omp_get_thread_num());

#pragma omp for reduction(+:m)
        for (int i = 0; i < n; i++)
        {
            // double x = (double) arc4random() / 0xFFFFFFFF;
            // double y = (double) arc4random() / 0xFFFFFFFF;
            double x = erand48(seed);
            double y = erand48(seed);
            if (x * x + y * y < 1.)
            {
                m++;
            }
        }
    }

    double pi = 4.0 * m / n;
    return pi;
}