#include "utils.hpp"

int* Utils::getRandomList(int size, int minRange, int maxRange){
    int* l = (int*) malloc(sizeof(int) * size);

    srand(time(NULL));

    for (int i = 0; i < size; i++){
        l[i] = rand() % maxRange + minRange;
    }
    return l;
};

void Utils::printList(int* l, int size){
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << l[i] << ", ";
    }
    std::cout << l[size - 1] << std::endl;
};
