#include "vector.h"

template <typename T>
Vector<T>::Vector() : m_array(new T[INITIAL_SIZE+1]), m_size(0), m_capacity(INITIAL_SIZE) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_array;
}

template <typename T>
void Vector<T>::clear() {
    delete[] m_array;
    m_array = new T[INITIAL_SIZE+1];
    m_size = 0;
    m_capacity = INITIAL_SIZE;
}

template <typename T>
void Vector<T>::resize(size_t newSize) {
    T* array = new T[(m_capacity = newSize)+1];
    for (int i = min(m_size, m_capacity); i >= 0; i--)
        array[i] = m_array[i];
    delete[] m_array;
    m_array = array;
}

template <typename T>
void Vector<T>::reserve(size_t size) {
    if (size > m_capacity - m_size)
        resize((m_size + size) * FACTOR);
}

template <typename T>
size_t Vector<T>::size() {
    return m_size;
}

template <typename T>
size_t Vector<T>::capacity() {
    return m_capacity;
}

template <typename T>
bool Vector<T>::is_empty() {
    return !m_size;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return m_array[index];
}

template <typename T>
T Vector<T>::at(size_t index) {
    return index > m_size ? NULL : m_array[index];
}

template <typename T>
T Vector<T>::front() {
    return is_empty() ? NULL : m_array[0];
}

template <typename T>
T Vector<T>::back() {
    return is_empty() ? NULL : m_array[m_size - 1];
}

template <typename T>
T* Vector<T>::data() {
    return m_array;
}

template <typename T>
void Vector<T>::swap(size_t index, size_t anotherIndex) {
    T tmp = m_array[index];
    m_array[index] = m_array[anotherIndex];
    m_array[anotherIndex] = tmp;
}

template <typename T>
void Vector<T>::insert(size_t index, T element) {
    if (index < m_size) {
        if (m_size == m_capacity)
            resize(m_capacity*FACTOR);
        
        for (int i = m_size++; i > index; i--)
            m_array[i] = m_array[i-1];
        m_array[index] = element;
    } else push_back(element);
}

template <typename T>
void Vector<T>::push_back(T element) {
    if (m_size == m_capacity)
        resize(m_capacity*FACTOR);
    m_array[m_size++] = element;
}

template <typename T>
T Vector<T>::pop_back() {
    return is_empty() ? NULL : m_array[--m_size];
}
