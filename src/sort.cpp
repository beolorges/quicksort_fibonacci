#include <sort.hpp>

template <typename T>
void Sort<T>::swap(T** a, T** b){
    T c = **a;
    **a = **b;
    **b = c;
}

template <typename T>
T** Sort<T>::partition(T** begin, T** end){
    T** i = begin;
    T** j = begin;

    while (j <= end){
        if(*j < *end){
            swap(i, j);
            i++;
        }
        j++;
    }
    swap(i, end);

    return i;
}

template <typename T>
void Sort<T>::rQuickSort(T** begin, T** end){
    if(begin >= end) return;

    T** a = partition(begin, end);

    rQuickSort(begin, a);    
    rQuickSort(a + 1, end);    
};

template <typename T>
void Sort<T>::iQuickSort(T** begin, T** end){
    std::stack<T**> stack;
    
    stack.push(begin);
    stack.push(end);

    while (!stack.empty())
    {
        T** left = stack.top();
        stack.pop();

        T** right = stack.top();
        stack.pop();

        T** pivot = partition(left, right);
        if(pivot - 1 > left){
            stack.push(left);
            stack.push(pivot - 1);
        }

        if(pivot + 1 < right){
            stack.push(pivot + 1);
            stack.push(right);
        }
    }
};

template <typename T>
void Sort<T>::rQuickSortWInsertionsort(T** begin, T** end, int minPartition){
    if( end - begin <= minPartition ) {
        partition(begin, end);
        return;
    }

    T** a = partition(begin, end);

    rQuickSort(begin, a);    
    rQuickSort(a + 1, end);    
};

template <typename T>
void Sort<T>::iQuickSortWInsertionsort(T** begin, T** end, int minPartition){
    insertionSort(begin, end);

    std::stack<T**> stack;
    stack.push(begin);
    stack.push(end);

    while (!stack.empty())
    {
        T** left = stack.top();
        stack.pop();

        T** right = stack.top();
        stack.pop();

        if(right - left <= minPartition){
            insertionSort(left, right);
        } else {
            T** pivot = partition(left, right);
            if(pivot - 1 > left){
                stack.push(left);
                stack.push(pivot - 1);
            }

            if(pivot + 1 < right){
                stack.push(pivot + 1);
                stack.push(right);
            }
        }
    }

};

template <typename T>
void Sort<T>::insertionSort(T** begin, T** end){
    T* t1, *t2;
    T val;

    t1 = *begin;

    while (t1 <= *end)
    {
        val = *t1;
        t2 = (t1 - 1);

        while (t2 >= *begin && *t2 > val){
            *(t2 + 1) = *t2;
            t2 --;
        }
        *(t2 + 1) = val;
        t1++;
    }
};

template class Sort<int>;