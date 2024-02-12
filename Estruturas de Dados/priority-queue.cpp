#include "priority-queue.h"

template <class T, template<typename> class O>
T PriorityQueue<T, O>::dequeue() {
    if (BinaryHeap<T, O>::isEmpty())
        return NULL;
    else if (BinaryHeap<T, O>::data->size() == 1)
        return BinaryHeap<T, O>::data->pop_back();
    
    T removedElement = BinaryHeap<T, O>::data->front();
    BinaryHeap<T, O>::data->data()[0] = BinaryHeap<T, O>::data->pop_back();
    BinaryHeap<T, O>::heapify();

    return removedElement;
}
