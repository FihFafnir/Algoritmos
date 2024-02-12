#include "binary-heap.h"

template <class T, template<typename> class O>
BinaryHeap<T, O>::BinaryHeap() : data(new Vector<T>()) {}

template <class T, template<typename> class O> 
bool BinaryHeap<T, O>::isEmpty() {
    return data->is_empty();
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::insert(T element) {
    size_t 
        currentIndex = data->size(),
        parentIndex = currentIndex ? PARENT(currentIndex) : -1;
    O<T> operation;

    data->push_back(element);
    while (parentIndex != -1 && operation.operator()(data->at(currentIndex), data->at(parentIndex))) {
        data->swap(currentIndex, parentIndex);
        currentIndex = parentIndex;
        parentIndex = currentIndex ? PARENT(currentIndex) : -1;
    }
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::heapify() {
    if (data->size() <= 1)
        return;
        
    for (int i = data->size()/2 - 1; i >= 0; i--)
        heapify(i);
}

template <class T, template<typename> class O> 
void BinaryHeap<T, O>::heapify(size_t index) {
    size_t 
        biggestIndex = index,
        leftIndex = LEFT(index),
        rightIndex = RIGHT(index);
    O<T> operation;

    if (leftIndex < data->size() && operation.operator()(data->at(leftIndex), data->at(biggestIndex)))
        biggestIndex = leftIndex;
    if (rightIndex < data->size() && operation.operator()(data->at(rightIndex), data->at(biggestIndex)))
        biggestIndex = rightIndex;

    if (biggestIndex == index)
        return;
    
    data->swap(index, biggestIndex);
}