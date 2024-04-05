#ifndef SORT_HPP
#define SORT_HPP

#include <stack>

template <typename T>
class Sort
{
private:
    // This class should not be instantiated
    Sort(){};

    static T** partition(T** begin, T** end);
    static void swap(T** a, T** b);

    static void insertionSort(T** begin, T** end);

public:
    ~Sort(){};

    static void rQuickSort(T** begin, T** end);
    static void iQuickSort(T** begin, T** end);
    static void rQuickSortWInsertionsort(T** begin, T** end, int minPartition);
    static void iQuickSortWInsertionsort(T** begin, T** end, int minPartition);
    
};


#endif