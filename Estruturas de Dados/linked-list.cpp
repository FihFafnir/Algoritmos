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
LinkedListElement<T>* LinkedList<T>::locate(size_t index) {
    LinkedListElement<T>* currentElement;
    size_t length = size(), count;

    if (index >= length)
        return nullptr;

    if (index < length>>2) {
        count = 0;
        currentElement = m_head->next;
        while (count++ != index)
            currentElement = currentElement->next;
    } else {
        count = length - 1;
        currentElement = m_head->previous;
        while (count-- != index)
            currentElement = currentElement->previous;
    }

    return currentElement;
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
    LinkedListElement<T>* currentElement = locate(index);
    if (currentElement != nullptr)
        return currentElement->value;

    cout << "Invalid index" << endl;
    exit(0);
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
    LinkedListElement<T>* currentElement = locate(index);
    if (currentElement != nullptr)
        return currentElement->value;

    cout << "Invalid index" << endl;
    exit(0);
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
    if (currentElement != nullptr) 
        new LinkedListElement<T>(value, currentElement->previous, currentElement);

    cout << "Invalid index" << endl;
    exit(0);
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
    LinkedListElement<T>* currentElement = locate(index);
    return currentElement == nullptr ? NULL : remove(currentElement); 
}

template <typename T>
T LinkedList<T>::pop_front() {
    return isEmpty() ? NULL : remove(m_head->next);
}

template <typename T>
T LinkedList<T>::pop_back() {
    return isEmpty() ? NULL : remove(m_head->previous);
}

template<typename T>
void LinkedList<T>::swap(size_t index, size_t anotherIndex) {
    if (index > anotherIndex) {
        index ^= anotherIndex;
        anotherIndex ^= index;
        index ^= anotherIndex;
    }

    LinkedListElement<T>* firstElement = locate(index);
    LinkedListElement<T>* currentElement = firstElement;
    size_t count = index;
    T tmp;
    
    while (count++ != anotherIndex)
        currentElement = currentElement->next;

    tmp = firstElement->value;
    firstElement->value = currentElement->value;
    currentElement->value = tmp;
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
LinkedListElement<T*>* LinkedList<T*>::locate(size_t index) {
    LinkedListElement<T*>* currentElement;
    size_t length = size(), count;

    if (index >= length)
        return nullptr;

    if (index < length>>2) {
        count = 0;
        currentElement = m_head->next;
        while (count++ != index)
            currentElement = currentElement->next;
    } else {
        count = length - 1;
        currentElement = m_head->previous;
        while (count-- != index)
            currentElement = currentElement->previous;
    }

    return currentElement;
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
    LinkedListElement<T*>* currentElement = locate(index);
    if (currentElement != nullptr)
        return currentElement->value;

    cout << "Invalid index" << endl;
    exit(0);
}

template <typename T>
T& LinkedList<T*>::operator[](size_t index) {
    LinkedListElement<T*>* currentElement = locate(index);
    if (currentElement != nullptr)
        return currentElement->value;

    cout << "Invalid index" << endl;
    exit(0);
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
    if (currentElement != nullptr) 
        new LinkedListElement<T*>(value, currentElement->previous, currentElement);

    cout << "Invalid index" << endl;
    exit(0);
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
    LinkedListElement<T*>* currentElement = locate(index);
    return currentElement == nullptr ? NULL : remove(currentElement); 
}

template <typename T>
T* LinkedList<T*>::pop_front() {
    return isEmpty() ? NULL : remove(m_head->next);
}

template <typename T>
T* LinkedList<T*>::pop_back() {
    return isEmpty() ? NULL : remove(m_head->previous);
}

template<typename T>
void LinkedList<T*>::swap(size_t index, size_t anotherIndex) {
    if (index > anotherIndex) {
        index ^= anotherIndex;
        anotherIndex ^= index;
        index ^= anotherIndex;
    }

    LinkedListElement<T*>* firstElement = locate(index);
    LinkedListElement<T*>* currentElement = firstElement;
    size_t count = index;
    T* tmp;
    
    while (count++ != anotherIndex)
        currentElement = currentElement->next;

    // firstElement->value ^= currentElement->value;
    // currentElement->value ^= firstElement->value;
    // firstElement->value ^= currentElement->value;

    tmp = firstElement->value;
    firstElement->value = currentElement->value;
    currentElement->value = tmp;
}