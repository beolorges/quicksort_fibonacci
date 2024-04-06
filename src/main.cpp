#include <iostream>
#include <getopt.h>
#include "utils.hpp"
#include "sort.hpp"

using namespace std;

int main(int argc, char* argv[]){
    int* v, size, partition;
    bool recursive, insertion;

    while (1)
    {
        const int opt = getopt(argc, argv, "n:r:i:p:");
        if(opt == -1) break;

        switch (opt)
        {
        case 'n':
            size = atoi(optarg);
            break;
        
        case 'r':
            recursive = atoi(optarg) == 1 ? true : false;
            break;

        case 'i':
            insertion = atoi(optarg) == 1 ? true : false;
            break;

        case 'p':
            partition = atoi(optarg);
            break;

        default:
            break;
        }
    }

    v = Utils::getRandomList(size, 0, 100);   
    int* lastElement = (v+size);
    if(recursive && !insertion)
        Sort<int>::rQuickSort(&v, &lastElement);
    
    else if(recursive && insertion)
        Sort<int>::rQuickSortWInsertionsort(&v, &lastElement, partition);
    
    else if(!recursive && !insertion)
        Sort<int>::iQuickSort(&v, &lastElement);

    else if(!recursive && insertion)
        Sort<int>::iQuickSortWInsertionsort(&v, &lastElement, partition);

    Utils::printList(v, size);
    free(v);
}