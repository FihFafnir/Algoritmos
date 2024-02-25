#include "linked-list.h"

template <typename T>
LinkedListElement<T>::LinkedListElement() : previous(this), next(this) {}

template <typename T>
LinkedListElement<T>::LinkedListElement(T value) : value(value), previous(this), next(this) {}

template <typename T>
LinkedListElement<T>::LinkedListElement(LinkedListElement<T>* previous, LinkedListElement<T>* next) : previous(previous), next(next) {
    previous->next = next->previous = this;
}

template <typename T>
LinkedListElement<T>::LinkedListElement(T value, LinkedListElement<T>* previous, LinkedListElement<T>* next) : value(value), previous(previous), next(next) {
    previous->next = next->previous = this;
}

template <typename T>
LinkedListElement<T*>::LinkedListElement() : value(new T()), previous(this), next(this) {}

template <typename T>
LinkedListElement<T*>::LinkedListElement(T* value) : value(value), previous(this), next(this) {}

template <typename T>
LinkedListElement<T*>::LinkedListElement(LinkedListElement<T*>* previous, LinkedListElement<T*>* next) : value(new T()), previous(previous), next(next) {
    previous->next = next->previous = this;
}

template <typename T>
LinkedListElement<T*>::LinkedListElement(T* value, LinkedListElement<T*>* previous, LinkedListElement<T*>* next) : value(value), previous(previous), next(next) {
    previous->next = next->previous = this;
}

template <typename T>
LinkedList<T>::LinkedList() : m_head(new LinkedListElement<T>()) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return m_head->next == m_head;
}

template <typename T>
void LinkedList<T>::clear() {
    while (!isEmpty())
        pop_front();
}

template <typename T>
size_t LinkedList<T>::size() {
    LinkedListElement<T>* currentElement = m_head;
    size_t count = 0;

    while (currentElement = currentElement->next, currentElement != m_head)
        count++;
    
    return count;
}

template <typename T>
LinkedListElement<T>* LinkedList<T>::begin() {
    return m_head->next;
}

template <typename T>
LinkedListElement<T>* LinkedList<T>::end() {
    return m_head->previous;
}

template <typename T>
LinkedListElement<T>* LinkedList<T>::locate(size_t index, size_t beginningIndex, LinkedListElement<T>* ptr) {
    LinkedListElement<T>* currentElement = ptr;
    size_t count = beginningIndex;

    if (count < index) 
        while (count++ != index)
            currentElement = currentElement->next;
    else while (count-- != index)
            currentElement = currentElement->previous;

    return currentElement;
}

template <typename T>
LinkedListElement<T>* LinkedList<T>::locate(size_t index) {
    LinkedListElement<T>* currentElement;
    size_t length = size();

    if (index >= length)
        throw runtime_error("Invalid index locate.");

    return index < (length>>1) ? 
        locate(index, 0, m_head->next) : 
        locate(index, length - 1, m_head->previous);
}

template <typename T>
T& LinkedList<T>::front() {
    return m_head->next->value;
}

template <typename T>
T& LinkedList<T>::back() {
    return m_head->previous->value;
}

template <typename T>
T& LinkedList<T>::at(size_t index) {
    return locate(index)->value;
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
    return locate(index)->value;
}

template <typename T>
void LinkedList<T>::push_front(T value) {
    new LinkedListElement<T>(value, m_head, m_head->next);
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    new LinkedListElement<T>(value, m_head->previous, m_head);
}

template <typename T>
void LinkedList<T>::insert(size_t index, T value) {
    LinkedListElement<T>* currentElement = locate(index);
    new LinkedListElement<T>(value, currentElement->previous, currentElement);
}

template <typename T>
T LinkedList<T>::remove(LinkedListElement<T>* ptr) {
    T removedElementValue = ptr->value;
    ptr->previous->next = ptr->next;
    ptr->next->previous = ptr->previous;

    delete ptr;
    return removedElementValue;
}

template <typename T>
T LinkedList<T>::remove(size_t index) {
    return remove(locate(index)); 
}

template <typename T>
T LinkedList<T>::pop_front() {
    if (isEmpty())
        throw runtime_error("Invalid index remove.");
    return remove(m_head->next);
}

template <typename T>
T LinkedList<T>::pop_back() {
    if (isEmpty())
        throw runtime_error("Invalid index remove.");
    return remove(m_head->previous);
}

template<typename T>
void LinkedList<T>::swap(size_t index, size_t anotherIndex) {
    if (index > anotherIndex) {
        index ^= anotherIndex;
        anotherIndex ^= index;
        index ^= anotherIndex;
    }

    LinkedListElement<T>* firstElement = locate(index);
    LinkedListElement<T>* secondElement = locate(anotherIndex, index, firstElement);
    T tmp;
    
    tmp = firstElement->value;
    firstElement->value = secondElement->value;
    secondElement->value = tmp;
}

template <typename T>
LinkedList<T*>::LinkedList() : m_head(new LinkedListElement<T*>()) {}

template <typename T>
LinkedList<T*>::~LinkedList() {
    clear();
}

template <typename T>
bool LinkedList<T*>::isEmpty() {
    return m_head->next == m_head;
}

template <typename T>
void LinkedList<T*>::clear() {
    while (!isEmpty())
        delete pop_front();
}

template <typename T>
size_t LinkedList<T*>::size() {
    LinkedListElement<T*>* currentElement = m_head; 
    size_t count = 0;
    while (currentElement = currentElement->next, currentElement != m_head)
        count++;
    return count;
}

template <typename T>
LinkedListElement<T*>* LinkedList<T*>::begin() {
    return m_head->next;
}

template <typename T>
LinkedListElement<T*>* LinkedList<T*>::end() {
    return m_head->previous;
}

template <typename T>
LinkedListElement<T*>* LinkedList<T*>::locate(size_t index, size_t beginningIndex, LinkedListElement<T*>* ptr) {
    LinkedListElement<T*>* currentElement = ptr;
    size_t count = beginningIndex;

    if (count < index) 
        while (count++ != index)
            currentElement = currentElement->next;
    else while (count-- != index)
            currentElement = currentElement->previous;

    return currentElement;
}

template <typename T>
LinkedListElement<T*>* LinkedList<T*>::locate(size_t index) {
    LinkedListElement<T*>* currentElement;
    size_t length = size();

    if (index >= length)
        throw runtime_error("Invalid index locate.");

    return index < (length>>1) ? 
        locate(index, 0, m_head->next) : 
        locate(index, length - 1, m_head->previous);
}

template <typename T>
T& LinkedList<T*>::front() {
    return m_head->next->value;
}

template <typename T>
T& LinkedList<T*>::back() {
    return m_head->previous->value;
}

template <typename T>
T& LinkedList<T*>::at(size_t index) {
    return locate(index)->value;
}

template <typename T>
T& LinkedList<T*>::operator[](size_t index) {
    return locate(index)->value;
}

template <typename T>
void LinkedList<T*>::push_front(T* value) {
    new LinkedListElement<T*>(value, m_head, m_head->next);
}

template <typename T>
void LinkedList<T*>::push_back(T* value) {
    new LinkedListElement<T*>(value, m_head->previous, m_head);
}

template <typename T>
void LinkedList<T*>::insert(size_t index, T* value) {
    LinkedListElement<T*>* currentElement = locate(index);
    new LinkedListElement<T*>(value, currentElement->previous, currentElement);
}

template <typename T>
T* LinkedList<T*>::remove(LinkedListElement<T*>* ptr) {
    T* removedElementValue = ptr->value;
    ptr->previous->next = ptr->next;
    ptr->next->previous = ptr->previous;

    delete ptr;
    return removedElementValue;
}

template <typename T>
T* LinkedList<T*>::remove(size_t index) {
    return remove(locate(index)); 
}

template <typename T>
T* LinkedList<T*>::pop_front() {
    if (isEmpty())
        throw runtime_error("Removing element from an empty linked list.");
    return remove(m_head->next);
}

template <typename T>
T* LinkedList<T*>::pop_back() {
    if (isEmpty())
        throw runtime_error("Removing element from an empty linked list.");
    return remove(m_head->previous);
}

template<typename T>
void LinkedList<T*>::swap(size_t index, size_t anotherIndex) {
    if (index > anotherIndex) {
        index ^= anotherIndex;
        anotherIndex ^= index;
        index ^= anotherIndex;
    }

    LinkedListElement<T*>* firstElement = locate(index);
    LinkedListElement<T*>* secondElement = locate(anotherIndex, index, firstElement);
    T tmp;
    
    tmp = firstElement->value;
    firstElement->value = secondElement->value;
    secondElement->value = tmp;
}