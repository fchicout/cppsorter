#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> data;
    int vectorInitialSize = 10;
    int minRange=0, maxRange=100;

    data.resize(vectorInitialSize);

    for (int i = 0; i < vectorInitialSize; i++)
    {
        data[i] = rand() % ((maxRange-minRange+1)+minRange) ;
    }

    for (int i = 0; i < vectorInitialSize; i++)
    {
        std::cout << data[i] << " " << std::endl;
    }

    return 0;
}
