#include "pair.h"

template <typename T>
Pair<T>::Pair() {}

template <typename T>
Pair<T>::Pair(T first, T second) : first(first), second(second) {}

template <typename T>
T& Pair<T>::operator[](size_t index) {
    return m_data[index];
}