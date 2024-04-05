#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

class Utils
{
private:
    Utils(/* args */){};
public:
    ~Utils(){};

    static int* getRandomList(int size, int minRange, int maxRange);
    static void printList(int* l, int size);
};

#endif