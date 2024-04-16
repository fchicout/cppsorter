#include "Sorter.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    const int vectorInitialSize = 10;
    int minRange = 50, maxRange = 150;

    Sorter sorter(vectorInitialSize);

    sorter.sampleIntegerVector(minRange, maxRange);
    sorter.printVector();
    sorter.quickSort(0, vectorInitialSize - 1, true);
    sorter.printVector();

    return 0;
}