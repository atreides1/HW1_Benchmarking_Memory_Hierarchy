#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//returns the char of the <buffer_string> at index <val>
char access_val(string buffer_string,unsigned int val)
{
        return buffer_string[val];
}

//returns a random value
unsigned int return_rand(unsigned int upper_limit)
{
        return rand()%upper_limit;
}

//loops and randomly populates a buffer of <buffer_size>
//then measures the latency of accessing multiple bytes
int run_benchmark(unsigned int buffer_size)
{
        struct timespec t0, t1, t2, t3;
        const int NSECS_IN_SEC = 1000000000;

        string buffer(buffer_size, 'a');//Create a string of bufferlength of chars
        srand(time(NULL));//Seed rand

        unsigned int rand_array [100000];
        for (int j= 0; j<100000; j++)
        {
                rand_array[j]= return_rand(buffer_size);
        }


        //time this
        clock_gettime(CLOCK_MONOTONIC, &t0);
                for (unsigned int i = 0; i<100000; i++) //access a part of memory #accesses times
                {
                        access_val(buffer, rand_array[i]);
                }
        //time end. mean time = div by iters.
        clock_gettime(CLOCK_MONOTONIC, &t1);
        const double time_span = (NSECS_IN_SEC * (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec)) / (double) 100000;
        long double mean_time = time_span / 100000;

        clock_gettime(CLOCK_MONOTONIC, &t2);
                for (unsigned int i = 0; i<100000; i++) //access a part of memory #accesses times
                {
                        unsigned int testing_time = rand_array[i]; //Just need to access values - Throws error, but most accurate timing
                }

        clock_gettime(CLOCK_MONOTONIC, &t3);
        const double rand_array_time = (NSECS_IN_SEC * (t3.tv_sec - t2.tv_sec) + (t3.tv_nsec - t2.tv_nsec)) / (double) 100000;
        //Subtract time to accesss vals consecutively in array/iters
        long double adjusted_time = (time_span - rand_array_time) / 1000;

        cout << buffer_size << "\t\t\t" << mean_time << "\t\t" <<adjusted_time << '\n';

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
