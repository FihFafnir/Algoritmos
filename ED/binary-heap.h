#pragma once
#include "vector.cpp"

#define PARENT(index) (index ? (index-1) >> 1 : -1);
#define LEFT(index) (index << 1) + 1
#define RIGHT(index) (index + 1) << 1;

template <class T, template<typename> class O = greater>
class BinaryHeap {
    protected:
        Vector<T> data;
    public:
        BinaryHeap();
        bool isEmpty();
        void insert(T element);
        void heapify();
        void heapify(size_t index);
};