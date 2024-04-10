#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void sampleIntegerVector(std::vector<int> &array, int size, int min, int max)
{
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % ((max - min + 1) + min);
    }
}

void printVector(){
    
}

int main(int argc, char const *argv[])
{
    std::vector<int> data;
    int vectorInitialSize = 10;
    int minRange = 0, maxRange = 100;

    data.resize(vectorInitialSize);

    sampleIntegerVector(data, vectorInitialSize, minRange, maxRange);

    for (int i = 0; i < vectorInitialSize; i++)
    {
        std::cout << data[i] << " " << std::endl;
    }

    return 0;
}