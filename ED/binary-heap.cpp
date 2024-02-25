#include "binary-heap.h"

template <class T, template<typename> class O>
BinaryHeap<T, O>::BinaryHeap() {}

template <class T, template<typename> class O> 
bool BinaryHeap<T, O>::isEmpty() {
    return data.is_empty();
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::insert(T element) {
    size_t 
        currentIndex = data.size(),
        parentIndex = PARENT(currentIndex);
    O<T> operation;

    data.push_back(element);
    while (parentIndex != -1 && operation.operator()(data[currentIndex], data[parentIndex])) {
        data.swap(currentIndex, parentIndex);
        currentIndex = parentIndex;
        parentIndex = PARENT(currentIndex);
    }
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::heapify() {
    if (data.size() > 1)    
        for (int i = (data.size() >> 1) - 1; i >= 0; i--)
            heapify(i);
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::heapify(size_t index) {
    size_t 
        parentIndex = index,
        leftIndex = LEFT(index),
        rightIndex = RIGHT(index);
    O<T> operation;

    if (leftIndex < data.size() && operation.operator()(data[leftIndex], data[parentIndex]))
        parentIndex = leftIndex;
    if (rightIndex < data.size() && operation.operator()(data[rightIndex], data[parentIndex]))
        parentIndex = rightIndex;

    if (parentIndex != index)
        data.swap(index, parentIndex);   
}