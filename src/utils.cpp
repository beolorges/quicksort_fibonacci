#include "utils.hpp"


using namespace std;

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


unsigned long long Utils::iGenerateFibonnacci(int timeLimit, std::chrono::_V2::system_clock::time_point initialTime){

    unsigned long long count = 0;

    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = now-initialTime;

    while (elapsedSeconds.count() < timeLimit)
    {
        unsigned long long temp = iGenerateFibonnacci(count);

        count++;

        now = std::chrono::system_clock::now();
        elapsedSeconds = now - initialTime;
    }

    return count;
};


unsigned long long Utils::iGenerateFibonnacci(unsigned long long n){
    if(n == 0 || n == 1) return 1;

    int n1 = 1;
    int n2 = 1;

    for (unsigned long long i = 2; i < n; i++)
    {
        int temp = n1 + n2;
        n2 = n1;
        n1 = temp;
    }
    
    return n1;
};


unsigned long long Utils::rGenerateFibonnacci(int timeLimit, std::chrono::_V2::system_clock::time_point initialTime){

    unsigned long long count = 0;

    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = now-initialTime;

    while (elapsedSeconds.count() < timeLimit)
    {
        unsigned long long temp = rGenerateFibonnacci(count);

        count++;

        now = std::chrono::system_clock::now();
        elapsedSeconds = now - initialTime;
    }

    return count;
};


unsigned long long Utils::rGenerateFibonnacci(unsigned long long n){
    if(n == 0 || n == 1) return 1;

    return rGenerateFibonnacci(n - 1)  + rGenerateFibonnacci(n - 2);
};

