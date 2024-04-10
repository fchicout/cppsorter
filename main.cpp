#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> data;
    int vectorInitialSize = 10;

    data.resize(vectorInitialSize);

    for (int i = 0; i < vectorInitialSize; i++)
    {
        data[i] = rand();
    }
    
    

    for (int i = 0; i < vectorInitialSize; i++)
    {
        std::cout << data[i] << " " <<  std::endl;
    }
    

    return 0;
}
