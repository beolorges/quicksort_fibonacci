#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <chrono>
#include <ctime> 

class Utils
{
private:
    Utils(){};

    static unsigned long long iGenerateFibonnacci(unsigned long long n);
    static unsigned long long rGenerateFibonnacci(unsigned long long n);

public:
    ~Utils(){};

    /**
     * @return Number of fibonnacci numbers generated
    */
    static unsigned long long iGenerateFibonnacci(int timeLimit, 
        std::chrono::_V2::system_clock::time_point initialTime = std::chrono::system_clock::now());

    static unsigned long long rGenerateFibonnacci(int timeLimit, 
        std::chrono::_V2::system_clock::time_point initialTime = std::chrono::system_clock::now());

    static int* getRandomList(int size, int minRange, int maxRange);
    static void printList(int* l, int size);
};

#endif