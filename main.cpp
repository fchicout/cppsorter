#include "Sorter.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    const int vectorInitialSize = 200;
    int minRange = 0, maxRange = 100;

    Sorter sorter(vectorInitialSize);
    
    sorter.sampleIntegerVector(minRange, maxRange);
    sorter.printVector();
    sorter.compareSorts();

    return 0;
}