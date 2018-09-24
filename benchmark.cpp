#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//returns the char of the <buffer_string> at index <val>
char access_val(string buffer_string,unsigned int val)
{
        return buffer_string.at(val);
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

        //string str1 = "abcdefghijklmnopqrstuvwxyz";
        string buffer(buffer_size, 'a');//Create a string of bufferlength of chars
        srand(time(NULL));//Seed rand

        unsigned int rand_array [1000];
        for (int j= 0; j<1000; j++)
        {
                rand_array[j]= return_rand(buffer_size);
        }


        //time this
        steady_clock::time_point t1 = steady_clock::now();
                for (unsigned int i = 0; i<1000; i++) //access a part of memory #accesses times
                {
                        access_val(buffer, rand_array[i]);
                }
        //time end. mean time = div by iters.
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        long double mean_time = time_span.count() / 1000;
        cout << buffer_size << "\t\t" << mean_time << '\n';
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

