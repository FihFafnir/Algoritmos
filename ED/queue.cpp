#include "queue.h"

template <typename T>
QueueElement<T>::QueueElement() : next(this), previous(this) {}

template <typename T>
QueueElement<T>::QueueElement(T value) : value(value), next(this), previous(this) {}

template <typename T>
QueueElement<T>::QueueElement(QueueElement<T>* previous, QueueElement<T>* next) : previous(previous), next(next) {
    next->previous = this;
    previous->next = this;
}

template <typename T>
QueueElement<T>::QueueElement(T value, QueueElement<T>* previous, QueueElement<T>* next) : value(value), previous(previous), next(next) {
    next->previous = this;
    previous->next = this;
}

template<typename T>
Queue<T>::Queue() : head(new QueueElement<T>()) {}

template<typename T>
Queue<T>::~Queue() {
    clear();
}

template<typename T>
bool Queue<T>::isEmpty() {
    return head->next == head;
}

template<typename T>
size_t Queue<T>::size() {
    QueueElement<T>* currentElement = head;
    size_t count = 0;
    while (currentElement = currentElement->next, currentElement != head)
        count++;
    return count;
}

template<typename T>
T Queue<T>::front() {
    return head->previous->value;
}

template<typename T>
T Queue<T>::back() {
    return head->next->value;
}

template<typename T>
void Queue<T>::push(T element) {
    new QueueElement<T>(element, head, head->next);
}

template<typename T>
T Queue<T>::pop() {
    if (isEmpty())
        throw runtime_error("Removing element from an empty queue.");

    QueueElement<T>* removedElement = head->previous;
    T removedElementValue = removedElement->value;
    head->previous = removedElement->previous;
    head->previous->next = head;

    delete removedElement;
    return removedElementValue;
}

template<typename T>
void Queue<T>::clear() {
    while (!isEmpty())
        pop();
}