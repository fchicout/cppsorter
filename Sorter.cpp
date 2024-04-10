#include "Sorter.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <algorithm> // For std::swap
#include <chrono>    // For timing

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

void Sorter::bubbleSort(bool debug = false)
{
    int swaps = 0;
    int iterations = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                // Swap array[j] and array[j + 1] using std::swap
                std::swap(data[j], data[j + 1]);
                swaps++;
            }
        }
        iterations++;
        if (debug)
        {
            std::cout << "After iteration " << i + 1 << ":" << std::endl;
            Sorter::printVector();
        }
    }
    std::cout << "Bubble Sort - Number of swaps: " << swaps << std::endl;
    std::cout << "Bubble Sort - Number of iterations: " << iterations << std::endl;
}

void Sorter::selectionSort(bool debug = false)
{
    int swaps = 0;
    int iterations = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(data[i], data[minIndex]);
            swaps++;
        }
        iterations++;
        if (debug)
        {
            std::cout << "After iteration " << i + 1 << ":" << std::endl;
            Sorter::printVector();
        }
    }
    std::cout << "Selection Sort - Number of swaps: " << swaps << std::endl;
    std::cout << "Selection Sort - Number of iterations: " << iterations << std::endl;
}

void Sorter::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}

void Sorter::merge(int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = data[middle + 1 + j];

    // Merge the temp arrays back into data[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            data[k] = leftArray[i];
            i++;
        } else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        data[k] = rightArray[j];
        j++;
        k++;
    }
}


void Sorter::compareSorts()
{
    std::vector<int> originalArray = data; // Store the original array for comparison
    auto startTime = std::chrono::high_resolution_clock::now();
    bubbleSort();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto bubbleSortDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    data = originalArray; // Reset the array to its original state
    startTime = std::chrono::high_resolution_clock::now();
    selectionSort();
    endTime = std::chrono::high_resolution_clock::now();
    auto selectionSortDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    std::cout << "Bubble Sort Duration: " << bubbleSortDuration << " milliseconds" << std::endl;
    std::cout << "Selection Sort Duration: " << selectionSortDuration << " milliseconds" << std::endl;
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
