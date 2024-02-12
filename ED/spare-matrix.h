#pragma once
#include <bits/stdc++.h>
#include "linked-list.cpp"

using namespace std;

template <typename T>
struct SpareMatrixElement {
    T value;
    size_t column;

    SpareMatrixElement();
    SpareMatrixElement(long int value);
    SpareMatrixElement(T value, size_t column);
};

template <typename T, size_t R, size_t C>
class SpareMatrix {
    LinkedList<SpareMatrixElement<T>> m_data[R];
    
    public:
        void insert(size_t row, size_t column, T element);
        T& operator[](size_t row);
        T& at(size_t row, size_t column);
        bool isValid(size_t row, size_t column);
        T remove(size_t row, size_t column);
        void clear();
};