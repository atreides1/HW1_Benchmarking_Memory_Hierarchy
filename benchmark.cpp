#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Getting random values so we can choose random access locations in buffer string
unsigned int return_rand(unsigned int upper_limit)
{
        return rand()%upper_limit;
}

//Creates and reads a string 6 MB long so the cache is "flooded" with useless information
void floodcache()
{
        const int six_MB = 6000000;
        string long_string(six_MB, 'm' );
        /*On occasion, single character values will be established, used, then posted after a loop
        This is to ensure the compiler does not "optimize" out unused variables.
        The produced column of these printed characters is ignored in our final evaluation of data*/
        char p;
        for (int k=0; k<six_MB;k++)
        {
                p = long_string[k];
        }
        cout << p;
}

//Our main function for bencharking time of random accesses to a string, buffer.
int run_benchmark(unsigned int buffer_size)
{
        struct timespec t0, t1, t2, t3;
        const int NSECS_IN_SEC = 1000000000;
        //n-byte string so we can have n potential bytes to access
        string buffer(buffer_size, 'a');
        //Need seed to be as random as possible each time so the prefetcher cannot "guess" where we will access next
        srand(time(NULL));
        unsigned int* rand_array = NULL;

        //Create and populate an array of random values which will correspond to the locations we access in the buffer string
        rand_array = new unsigned int[buffer_size];
        for (unsigned int j= 0; j<buffer_size; j++)
        {
                rand_array[j]= return_rand(buffer_size);
        }

        //Flood out rand array and access info in cache for "clean" start
        floodcache();
        char y;
        //Buffer first stored in the cache, so larger buffers will not fit in L1/L2.
        for (unsigned int n = 0; n<buffer_size;n++)
        {
                y = buffer[n];

        }
        cout << y;

        const int iters = 10;

        //Measure time to access rand chars in buffer iters times.
        char o;
        clock_gettime(CLOCK_MONOTONIC_RAW, &t0);
        for (unsigned int z = 0; z < iters; z++)
        {

                for (unsigned int i = 0; i<buffer_size; i++)
                {
                        o = buffer[rand_array[i]];
                }
        }
        clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
         //time end. mean time = measured/iters. Converted to nanoseconds to compare to expected L1/L2 access times
        cout << o;
        const double time_span = (NSECS_IN_SEC * (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec)) / (double) buffer_size;
        long double mean_time = time_span;

        //Measure time to iter through rand array since it affects time measured above. Subtract this from time_span to get mean adj time
        unsigned int testing_time;
        clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
                for (unsigned int i = 0; i<buffer_size; i++)
                {
                        testing_time = rand_array[i];
                }

        clock_gettime(CLOCK_MONOTONIC_RAW, &t3);
        cout << testing_time%2 << '\t';
        const double rand_array_time = (NSECS_IN_SEC * (t3.tv_sec - t2.tv_sec) + (t3.tv_nsec - t2.tv_nsec)) / (double) buffer_size;

        long double adjusted_time = time_span - (iters * rand_array_time);
        cout << buffer_size << "\t\t\t" << mean_time << "\t\t" <<adjusted_time << '\n';

        delete [] rand_array;
        return 0;

}

int main ()
{
        // Run benchmark for buffers size 2^10 to 2^26
        int buffer_size = 1024;
        while (buffer_size <= 67108864)
        {

                run_benchmark(buffer_size);
                run_benchmark(buffer_size);
                run_benchmark(buffer_size);
                buffer_size *= 2;
        }
        return 0;
}
