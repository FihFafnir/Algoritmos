#pragma once
#include "vector.cpp"

#define PARENT(i) (i-1)/2
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*(i + 1)

template <class T, template<typename> class O = greater>
class BinaryHeap {
    protected:
        Vector<T>* data;
    public:
        BinaryHeap();
        bool isEmpty();
        void insert(T element);
        void heapify();
        void heapify(size_t index);
};