#include "array.h"

template <typename T, size_t S>
Array<T, S>::Array() {
    memset(m_data, 0, sizeof(m_data));
}

template <typename T, size_t S>
Array<T, S>::Array(T& element, ...) {
    va_list args;
    va_start(args, element);

    for (int i = 0; i < S; i++)
        m_data[i] = va_arg(args, T);
    
    va_end(args);
}

template <typename T, size_t S>
Array<T, S>::Array(T (&arr)[S]) {
    memcpy(m_data, arr, sizeof(m_data));
}

template <typename T, size_t S>
bool Array<T, S>::is_empty() {
    return !S;
}

template <typename T, size_t S>
size_t Array<T, S>::size() {
    return S;
}

template <typename T, size_t S>
T* Array<T, S>::data() {
    return m_data;
}

template <typename T, size_t S>
T& Array<T, S>::operator[](size_t index) {
    if (index < S)
        return m_data[index];
    throw runtime_error("Invalid index access.");
}

template <typename T, size_t S>
T& Array<T, S>::at(size_t index) {
    if (index < S)
        return m_data[index];
    throw runtime_error("Invalid index access.");    
}

template <typename T, size_t S>
T& Array<T, S>::front() {
    return m_data[0];
}

template <typename T, size_t S>
T& Array<T, S>::back() {
    return m_data[S - 1];
}

template <typename T, size_t S>
void Array<T, S>::fill(T element) {
    for (int i = 0; i < S; i++)
        m_data[i] = element;
}

template <typename T, size_t S>
void Array<T, S>::swap(size_t index, size_t anotherIndex) {
    if (index < S && anotherIndex < S) {
        T tmp = m_data[index];
        m_data[index] = m_data[anotherIndex];
        m_data[anotherIndex] = tmp;
    } else throw runtime_error("Invalid index access.");    
}