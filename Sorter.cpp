#include "Sorter.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Sorter::Sorter(int size) : size(size)
{
    data.resize(size);
}

void Sorter::sampleIntegerVector(int min, int max)
{
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % ((max - min + 1) + min);
    }
}
void Sorter::printVector()
{
    std::cout << "Vector elements:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
