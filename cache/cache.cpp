#include <cstdlib>
#include <iostream>
#include <new>

#include <boost/timer/timer.hpp>

void fill(int* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
}

void measure(int* arr, size_t size, size_t step)
{
    std::cout << size << "," << step << "," << std::flush;

    boost::timer::auto_cpu_timer timer("%w\n");

    for (size_t i = 0; i < size; i += step)
    {
        arr[i]++;
    }

    std::cout << std::flush;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " array_size" << std::endl;
        return 0;
    }

    size_t const size = atoi(argv[1]);

    int* arr = new int[size];

    fill(arr, size);

    std::cout << "array size,step,time (seconds)" << std::endl;
    for (size_t step = 1; step <= 16; ++step)
    {
        measure(arr, size, step);
    }

    delete[] arr;
}
