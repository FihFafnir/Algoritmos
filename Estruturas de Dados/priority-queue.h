#pragma once
#include "binary-heap.cpp"

template <class T, template<typename> class O = greater>
class PriorityQueue : public BinaryHeap<T, O> {
    public:
        T dequeue();
};