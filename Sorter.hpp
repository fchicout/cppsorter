#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>

class Sorter
{
public:
    Sorter(int size);

    void sampleIntegerVector(int min, int max);
    void bubbleSort(bool);
    void selectionSort(bool);
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);

    void compareSorts();
    void printVector();

private:
    std::vector<int> data;
    int size;
};

#endif /* SORTER_HPP */