#include "vector.h"

template <typename T, size_t S>
Vector<T, S>::Vector() : m_array(new T[INITIAL_SIZE+1]), m_size(0), m_capacity(INITIAL_SIZE) {}

template <typename T, size_t S>
Vector<T, S>::~Vector() {
    delete[] m_array;
}

template <typename T, size_t S>
void Vector<T, S>::clear() {
    delete[] m_array;
    m_array = new T[INITIAL_SIZE+1];
    m_size = 0;
    m_capacity = INITIAL_SIZE;
}

template <typename T, size_t S>
void Vector<T, S>::resize(size_t newSize) {
    T* array = new T[(m_capacity = newSize)+1];
    for (int i = min(m_size, m_capacity); i >= 0; i--)
        array[i] = m_array[i];
    delete[] m_array;
    m_array = array;
}

template <typename T, size_t S>
void Vector<T, S>::reserve(size_t size) {
    if (size > m_capacity - m_size)
        resize((m_size + size) * FACTOR);
}

template <typename T, size_t S>
size_t Vector<T, S>::size() {
    return m_size;
}

template <typename T, size_t S>
size_t Vector<T, S>::capacity() {
    return m_capacity;
}

template <typename T, size_t S>
bool Vector<T, S>::is_empty() {
    return !m_size;
}

template <typename T, size_t S>
T& Vector<T, S>::operator[](size_t index) {
    return m_array[index];
}

template <typename T, size_t S>
T& Vector<T, S>::at(size_t index) {
    return m_array[index];
}

template <typename T, size_t S>
T& Vector<T, S>::front() {
    return m_array[0];
}

template <typename T, size_t S>
T& Vector<T, S>::back() {
    return m_array[m_size - 1];
}

template <typename T, size_t S>
T* Vector<T, S>::data() {
    return m_array;
}

template <typename T, size_t S>
void Vector<T, S>::swap(size_t index, size_t anotherIndex) {
    T tmp = m_array[index];
    m_array[index] = m_array[anotherIndex];
    m_array[anotherIndex] = tmp;
}

template <typename T, size_t S>
void Vector<T, S>::insert(size_t index, T element) {
    if (index < m_size) {
        if (m_size == m_capacity)
            resize(m_capacity*FACTOR);
        
        for (int i = m_size++; i > index; i--)
            m_array[i] = m_array[i-1];
        m_array[index] = element;
    } else push_back(element);
}

template <typename T, size_t S>
void Vector<T, S>::push_back(T element) {
    if (m_size == m_capacity)
        resize(m_capacity*FACTOR);
    m_array[m_size++] = element;
}

template <typename T, size_t S>
T Vector<T, S>::pop_back() {
    if (is_empty())
        throw runtime_error("Removing element from an empty vector.");
    return m_array[--m_size];
}
