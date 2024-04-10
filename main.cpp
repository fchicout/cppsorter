#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Sorter
{
public:
    Sorter(int size) : size(size)
    {
        data.resize(size);
    }

    void sampleIntegerVector(int min, int max)
    {
        srand(time(nullptr));

        for (int i = 0; i < size; i++)
        {
            data[i] = rand() % ((max - min + 1) + min);
        }
    }
    void printVector()
    {
        std::cout << "Vector elements:" << std::endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> data;
    int size;
};

int main(int argc, char const *argv[])
{
    const int vectorInitialSize = 10;
    int minRange = 0, maxRange = 100;

    Sorter sorter(vectorInitialSize);
    
    sorter.sampleIntegerVector(minRange, maxRange);

    sorter.printVector();

    return 0;
}