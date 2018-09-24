#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
char access_val(string buffer_string,unsigned int val)
{
        return buffer_string.at(val);
}
unsigned int return_rand(unsigned int upper_limit)
{
        return rand()%upper_limit;
}

int main ()
{
        unsigned int buffer_size;
        cin >> buffer_size;//User input buffer size
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
        cout << mean_time << '\n';
        //be sure to time a for loop of the rand_array and subtract from time
        //also, automate
        return 0;
}
