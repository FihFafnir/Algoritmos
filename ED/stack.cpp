#include "stack.h"

template<typename T>
StackElement<T>::StackElement() : next(this) {}

template<typename T>
StackElement<T>::StackElement(T value) : value(value), next(this) {}

template<typename T>
StackElement<T>::StackElement(StackElement<T>* next) : next(next) {}

template<typename T>
StackElement<T>::StackElement(T value, StackElement<T>* next) : value(value), next(next) {}

template <typename T>
Stack<T>::Stack() : m_top(new StackElement<T>()) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
bool Stack<T>::isEmpty() {
    return m_top->next == m_top;
}

template <typename T>
size_t Stack<T>::size() {
    StackElement<T>* currentElement = m_top;
    size_t count = 0;
    
    while (currentElement = currentElement->next, currentElement != m_top)
        count++;
    return count;
}

template <typename T>
void Stack<T>::push(T element) {
    StackElement<T>* newElement = new StackElement<T>(element, m_top->next);
    m_top->next = newElement;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty())
        return NULL;

    StackElement<T>* removedElement = m_top->next;
    T removedElementValue = removedElement->value;
    m_top->next = removedElement->next;

    delete removedElement;
    return removedElementValue;
}

template <typename T>
T Stack<T>::top() {
    return isEmpty() ? NULL : m_top->next->value;
}

template <typename T>
void Stack<T>::clear() {
    StackElement<T>* removedElement;
    while (removedElement = m_top->next, !isEmpty()) {
        m_top->next = removedElement->next;
        delete removedElement;
    }
}