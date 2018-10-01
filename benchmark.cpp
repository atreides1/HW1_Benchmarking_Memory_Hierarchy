#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//returns a random value
unsigned int return_rand(unsigned int upper_limit)
{
        return rand()%upper_limit;
}

void floodcache()
{
        const int six_MB = 6000000;
        string long_string(six_MB, 'm' ); //create a string, then read it so it fills the cache
        char p;
        for (int k=0; k<six_MB;k++)
        {
                p = long_string[k];
        }
        cout << p;
}

//loops and randomly populates a buffer of <buffer_size>
//then measures the latency of accessing multiple bytes
int run_benchmark(unsigned int buffer_size)
{
        struct timespec t0, t1, t2, t3;
        const int NSECS_IN_SEC = 1000000000;

        string buffer(buffer_size, 'a');//Create a string of bufferlength of chars
        srand(time(NULL));//Seed rand

        unsigned int* rand_array = NULL;
        rand_array = new unsigned int[buffer_size];
        for (unsigned int j= 0; j<buffer_size; j++)
        {
                rand_array[j]= return_rand(buffer_size);
        }

        floodcache(); //Flood out rand array and access info for "clean" start
        char y;
        for (unsigned int n = 0; n<buffer_size;n++)//want all of our buffer to first be stored into the cache.
        {
                y = buffer[n];

        }
        cout << y;

        const int iters = 10;

        //time this
        char o;
        clock_gettime(CLOCK_MONOTONIC_RAW, &t0);
        for (unsigned int z = 0; z < iters; z++)
        {

                for (unsigned int i = 0; i<buffer_size; i++) //access a part of memory #accesses times
                {
                        o = buffer[rand_array[i]];
                }
        }
        //time end. mean time = div by iters.
        clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
        cout << o << '\t';
        const double time_span = (NSECS_IN_SEC * (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec)) / (double) buffer_size;
        long double mean_time = time_span;

        clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
                for (unsigned int i = 0; i<buffer_size; i++) //access a part of memory #accesses times
                {
                        unsigned int testing_time = rand_array[i]; //Just need to access values - Throws error, but most accurate timing
                }

        clock_gettime(CLOCK_MONOTONIC_RAW, &t3);
        const double rand_array_time = (NSECS_IN_SEC * (t3.tv_sec - t2.tv_sec) + (t3.tv_nsec - t2.tv_nsec)) / (double) buffer_size;
        //Subtract time to accesss vals consecutively in array/iters
        long double adjusted_time = time_span - (iters * rand_array_time);

        cout << buffer_size << "\t\t\t" << mean_time << "\t\t" <<adjusted_time << '\n';

        delete [] rand_array;
        return 0;

}

int main ()
{
        int buffer_size = 1024;
        while (buffer_size <= 67108864)
        {

                run_benchmark(buffer_size);
                buffer_size *= 2;
        }
        return 0;
}
