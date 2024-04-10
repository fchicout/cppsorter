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
    void mergeSort(int left, int right, bool debug);
    void quickSort(int left, int right, bool debug = false);

    void compareSorts();
    void printVector();

private:
    std::vector<int> data;
    int size;
    int merge(int left, int middle, int right, bool debug, int &iterations);
    int partition(int left, int right, bool debug = false);
};

#endif /* SORTER_HPP */