#include "deque.h"

template<typename T>
DequeElement<T>::DequeElement() : previous(this), next(this) {}

template<typename T>
DequeElement<T>::DequeElement(T value) : value(value), previous(this), next(this) {}

template<typename T>
DequeElement<T>::DequeElement(DequeElement<T>* previous, DequeElement<T>* next) : previous(previous), next(next) {
    next->previous = previous->next = this;
}

template<typename T>
DequeElement<T>::DequeElement(T value, DequeElement<T>* previous, DequeElement<T>* next) : value(value), previous(previous), next(next) {
    next->previous = previous->next = this;
}

template<typename T>
Deque<T>::Deque() : head(new DequeElement<T>()) {}

template<typename T>
Deque<T>::~Deque() {
    clear();
}

template<typename T>
bool Deque<T>::isEmpty() {
    return head->next == head;
}

template<typename T>
uint Deque<T>::size() {
    DequeElement<T>* currentElement = head;
    uint count = 0;
    while (currentElement = currentElement->next, currentElement != head)
        count++;
    return count;
}

template<typename T>
DequeElement<T>* Deque<T>::begin() {
    return head->next;
}

template<typename T>
DequeElement<T>* Deque<T>::end() {
    return head->previous;
}

template<typename T>
T& Deque<T>::front() {
    return head->next->value;
}

template<typename T>
T& Deque<T>::back() {
    return head->previous->value;
}

template<typename T>
T& Deque<T>::at(size_t index) {
    DequeElement<T>* currentElement = head;
    size_t count = 0;

    while (currentElement = currentElement->next, count != index) 
        count++;

    return currentElement->value;
}

template<typename T>
T& Deque<T>::operator[](size_t index) {
    DequeElement<T>* currentElement = head;
    size_t count = 0;

    while (currentElement = currentElement->next, count != index) 
        count++;

    return currentElement->value;
}

template<typename T>
void Deque<T>::insert(size_t index, T element) {
    if (index >= size())
        push_back(element);

    DequeElement<T>* currentElement = head->next;
    size_t count = 0;

    while (count++ != index)
        currentElement = currentElement->next

    new DequeElement<T>(element, currentElement->previous, currentElement);
}

template<typename T>
void Deque<T>::push_back(T element) {
    new DequeElement<T>(element, head->previous, head);
}

template<typename T>
void Deque<T>::push_front(T element) {
    new DequeElement<T>(element, head, head->next);
}

template<typename T>
T Deque<T>::remove(DequeElement<T>* ptr) {
    T removedElementValue = ptr->value;
    ptr->next->previous = ptr->previous;
    ptr->previous->next = ptr->next;

    delete ptr;
    return removedElementValue;
}

template<typename T>
T Deque<T>::remove(size_t index) {
    if (isEmpty())
        return NULL;

    DequeElement<T>* currentElement;
    size_t length = size(), count;

    if (index < length>>2) {
        count = 0;
        currentElement = head->next;
        while (count++ != index)
            currentElement = currentElement->next;
    } else {
        count = length - 1;
        currentElement = head->previous;
        while (count-- != index)
            currentElement = currentElement->previous;
    }

    return remove(currentElement);
}

template<typename T>
T Deque<T>::pop_back() {
    return isEmpty() ? NULL : remove(head->previous);
}

template<typename T>
T Deque<T>::pop_front() {
    return isEmpty() ? NULL : remove(head->next);
}

template<typename T>
void Deque<T>::clear() {
    while (!isEmpty())
        pop_front();
}

template<typename T>
void Deque<T>::swap(size_t index, size_t anotherIndex) {
    if (index > anotherIndex) {
        index ^= anotherIndex;
        anotherIndex ^= index;
        index ^= anotherIndex;
    }

    DequeElement<T>* currentElement = head->next;
    DequeElement<T>* firstElement;
    size_t count = 0;
    T tmp;

    while (count++ != index)
        currentElement = currentElement->next 

    firstElement = currentElement;
    
    while (count++ != anotherIndex)
        currentElement = currentElement->next;

    tmp = firstElement->value;
    firstElement->value = currentElement->value;
    currentElement->value = tmp;
}