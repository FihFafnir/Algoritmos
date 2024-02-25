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
Deque<T>::Deque() : m_head(new DequeElement<T>()) {}

template<typename T>
Deque<T>::~Deque() {
    clear();
}

template<typename T>
bool Deque<T>::isEmpty() {
    return m_head->next == m_head;
}

template<typename T>
size_t Deque<T>::size() {
    DequeElement<T>* currentElement = m_head;
    size_t count = 0;
    while (currentElement = currentElement->next, currentElement != m_head)
        count++;
    return count;
}

template <typename T>
DequeElement<T>* Deque<T>::locate(size_t index, size_t beginningIndex, DequeElement<T>* ptr) {
    DequeElement<T>* currentElement = ptr;
    size_t count = beginningIndex;

    if (count < index) 
        while (count++ != index)
            currentElement = currentElement->next;
    else while (count-- != index)
            currentElement = currentElement->previous;

    return currentElement;
}

template <typename T>
DequeElement<T>* Deque<T>::locate(size_t index) {
    DequeElement<T>* currentElement;
    size_t length = size();

    if (index >= length)
        throw runtime_error("Invalid index locate.");

    return index < (length>>1) ? 
        locate(index, 0, m_head->next) : 
        locate(index, length - 1, m_head->previous);
}

template<typename T>
DequeElement<T>* Deque<T>::begin() {
    return m_head->next;
}

template<typename T>
DequeElement<T>* Deque<T>::end() {
    return m_head->previous;
}

template<typename T>
T& Deque<T>::front() {
    return m_head->next->value;
}

template<typename T>
T& Deque<T>::back() {
    return m_head->previous->value;
}

template<typename T>
T& Deque<T>::at(size_t index) {
    return locate(index)->value;
}

template<typename T>
T& Deque<T>::operator[](size_t index) {
    return locate(index)->value;
}

template<typename T>
void Deque<T>::insert(size_t index, T element) {
    if (index >= size())
        push_back(element);

    DequeElement<T>* currentElement = locate(index);
    new DequeElement<T>(element, currentElement->previous, currentElement);
}

template<typename T>
void Deque<T>::push_back(T element) {
    new DequeElement<T>(element, m_head->previous, m_head);
}

template<typename T>
void Deque<T>::push_front(T element) {
    new DequeElement<T>(element, m_head, m_head->next);
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
    return remove(locate(index));
}

template<typename T>
T Deque<T>::pop_back() {
    if (isEmpty())
        throw runtime_error("Removing element from an empty deque.");
    return remove(m_head->previous);
}

template<typename T>
T Deque<T>::pop_front() {
    if (isEmpty())
        throw runtime_error("Removing element from an empty deque.");
    return remove(m_head->next);
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

    DequeElement<T>* firstElement = locate(index);
    DequeElement<T>* secondElement = locate(anotherIndex, index, firstElement);
    T tmp;
    
    tmp = firstElement->value;
    firstElement->value = secondElement->value;
    secondElement->value = tmp;
}