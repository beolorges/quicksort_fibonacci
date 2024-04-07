#include <iostream>
#include <getopt.h>
#include "utils.hpp"
#include "sort.hpp"
#include <math.h>

using namespace std;

#define RECURSIVE_QUICKSORT 1
#define RECURSIVE_QUICKSORT_INSERTION 2
#define ITERATIVE_QUICKSORT 3
#define ITERATIVE_QUICKSORT_INSERTION 4

#define RECURSIVE_FIBONACCI 1
#define ITERATIVE_FIBONACCI 2

#define INSERTION_SORT_PARTITION_SIZE 30
#define ARRAY_SIZE 10000
#define NUMBER_OF_EXPERIMENTS 50

#define MIN_RANDOM 1
#define MAX_RANDOM 100000

#define executeQuickSortFunction(i, ptr1, ptr2) ((void) ((i == RECURSIVE_QUICKSORT) ? __executeRQuickSort(ptr1, ptr2) \
    :  (i == RECURSIVE_QUICKSORT_INSERTION) ? __executeRQuickSortWInsertion(ptr1, ptr2) \
    : (i == ITERATIVE_QUICKSORT) ? __executeIQuickSort(ptr1, ptr2) \
    : __executeIQuickSortWInsertion(ptr1, ptr2)))

#define __executeRQuickSort(ptr1, ptr2) (Sort<int>::rQuickSort(ptr1,  ptr2))
#define __executeRQuickSortWInsertion(ptr1, ptr2) (Sort<int>::rQuickSortWInsertionsort(ptr1,  ptr2, INSERTION_SORT_PARTITION_SIZE))
#define __executeIQuickSort(ptr1, ptr2) (Sort<int>::iQuickSort(ptr1,  ptr2))
#define __executeIQuickSortWInsertion(ptr1, ptr2) (Sort<int>::iQuickSortWInsertionsort(ptr1,  ptr2, INSERTION_SORT_PARTITION_SIZE))

#define executeFibonacciFunction(i, time) ((int) (i == RECURSIVE_FIBONACCI) ? __executeRFibonacci(time) : __executeIFibonacci(time))

#define __executeRFibonacci(time) ((int) Utils::rGenerateFibonnacci(i))
#define __executeIFibonacci(time) ((int) Utils::iGenerateFibonnacci(i))

void execQuickSort(int func, int i, double* result){

    int *v = Utils::getRandomList(ARRAY_SIZE, MIN_RANDOM, MAX_RANDOM);   
    
    auto initialTime = std::chrono::system_clock::now();

    executeQuickSortFunction(func, v, v + ARRAY_SIZE - 1);
    
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = endTime - initialTime;

    result[i] = elapsedSeconds.count();

    free(v);
}

void printExecutionTimeData(FILE* f, const char* title, double* execs, int size ){
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += execs[i];
    }

    double med = sum / (double) size;

    double var = 0;

    for (int i = 0; i < size; i++) {
        double v = execs[i] - med;
        var += v * v;
    }

    double sigma = sqrt(var / size);

    fprintf(f, "%s - Media: %.10f\n", title, med);
    fprintf(f, "%s - Desvio Padrao: %.10f\n\n", title, sigma);
}


void printAndExecuteFibonnaci(FILE* f){

    fprintf(f, "           Recursivo - Interativo\n");

    for (int i = 15; i <= 120; i += 15){
        fprintf(f, "%d ", i);
        
        int exec = executeFibonacciFunction(RECURSIVE_FIBONACCI, i);
        fprintf(f, "%d ", exec);

        exec = executeFibonacciFunction(ITERATIVE_FIBONACCI, i);
        fprintf(f, "%d\n", exec);
    }
}

int main(int argc, char* argv[]){

    double* rQuickSortExecs = (double*) malloc(sizeof(double) * NUMBER_OF_EXPERIMENTS);
    double* rQuickSortWInsertExecs = (double*) malloc(sizeof(double) * NUMBER_OF_EXPERIMENTS);
    double* iQuickSortExecs = (double*) malloc(sizeof(double) * NUMBER_OF_EXPERIMENTS);
    double* iQuickSortWInsertExecs = (double*) malloc(sizeof(double) * NUMBER_OF_EXPERIMENTS);


    for (int i = 0; i < NUMBER_OF_EXPERIMENTS; i++){
        execQuickSort(RECURSIVE_QUICKSORT, i, rQuickSortExecs);
        execQuickSort(RECURSIVE_QUICKSORT_INSERTION, i, rQuickSortWInsertExecs);
        execQuickSort(ITERATIVE_QUICKSORT, i, iQuickSortExecs);
        execQuickSort(ITERATIVE_QUICKSORT_INSERTION, i, iQuickSortWInsertExecs);
    }

    FILE* f = fopen("./out/quicksort_result.txt", "w");
    fprintf(f, "---------------------- Resultados Quicksort ----------------------\n");

    if(f == NULL) return -1;

    printExecutionTimeData(f, "QuickSort Recursivo", rQuickSortExecs, NUMBER_OF_EXPERIMENTS);
    printExecutionTimeData(f, "QuickSort Recursivo com InsertionSort", rQuickSortWInsertExecs, NUMBER_OF_EXPERIMENTS);
    printExecutionTimeData(f, "QuickSort Iterativo", iQuickSortExecs, NUMBER_OF_EXPERIMENTS);
    printExecutionTimeData(f, "QuickSort Iterativo com InsertionSort", iQuickSortWInsertExecs, NUMBER_OF_EXPERIMENTS);

    fprintf(f, "---------------------- Resultados Fibonacci ----------------------\n");

    printAndExecuteFibonnaci(f);

    fclose(f);

}