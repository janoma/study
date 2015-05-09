#include <cstdlib>
#include <iostream>
#include <vector>

#include <boost/timer/timer.hpp>

void measure(std::vector<int>& arr, size_t step)
{
    std::cout << arr.size() << "," << step << "," << std::flush;

    boost::timer::auto_cpu_timer timer("%w\n");

    for (size_t i(0), size(arr.size()); i < size; i += step)
    {
        arr[i]++;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " array_size" << std::endl;
        return 0;
    }

    size_t const size = atoi(argv[1]);

    std::vector<int> arr(size, 0);

    std::cout << "array size,step,time (seconds)" << std::endl;
    for (size_t step = 1; step <= 16; ++step)
    {
        measure(arr, step);
    }
}
