#include "spare-matrix.h"

template <typename T>
SpareMatrixElement<T>::SpareMatrixElement() : value(0), column(-1) {}

template <typename T>
SpareMatrixElement<T>::SpareMatrixElement(long int value) : value(value), column(-1) {}

template <typename T>
SpareMatrixElement<T>::SpareMatrixElement(T value, size_t column) : value(value), column(column) {}

template <typename T, size_t R, size_t C>
void SpareMatrix<T, R, C>::insert(size_t row, size_t column, T element) {
    SpareMatrixElement<T> newElement = {element, column};
    m_data[row].add(min(column, m_data[row].size()), newElement);
}

template <typename T, size_t R, size_t C>
T& SpareMatrix<T, R, C>::operator[](size_t row) {
    if (row < R)
        return m_data[row];
    throw runtime_error("Invalid index access.");
}

template <typename T, size_t R, size_t C>
T& SpareMatrix<T, R, C>::at(size_t row, size_t column) {
    size_t size = m_data[row].size();
    for (int i = 0; i < size; i++)
        if (m_data[row][i].column == column)
            return m_data[row][i].value;
    throw runtime_error("Invalid index access.");    
}

template <typename T, size_t R, size_t C>
bool SpareMatrix<T, R, C>::isValid(size_t row, size_t column) {
    size_t size = m_data[row].size();
    for (int i = 0; i < size; i++)
        if (m_data[row][i].column == column)
            return true;
    return false;    
}

template <typename T, size_t R, size_t C>
T SpareMatrix<T, R, C>::remove(size_t row, size_t column) {
    if (!isValid(row, column))
        throw runtime_error("Invalid index remove.");    

    size_t size = m_data[row].size();
    for (int i = 0; i < size; i++)
        if (m_data[row][i].column == column)
            return m_data[row].remove(i);
}

