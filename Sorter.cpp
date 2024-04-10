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

void Sorter::bubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    // Swap array[j] and array[j + 1] using std::swap
                    std::swap(data[j], data[j + 1]);
                }
            }
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