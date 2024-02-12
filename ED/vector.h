#pragma once

#include <bits/stdc++.h>

#define INITIAL_SIZE 10
#define FACTOR 2

using namespace std;

template <typename T>
class Vector {
    T* m_array;
    size_t m_size;
    size_t m_capacity;

    public:
        Vector();
        ~Vector();
        size_t size();
        size_t capacity();
        void clear();
        void resize(size_t newSize);
        void reserve(size_t size);
        bool is_empty();

        T& operator[] (size_t index);
        T at(size_t index);
        T front();
        T back();
        T* data();
        void swap(size_t index, size_t anotherIndex);
        void insert(size_t index, T element);
        void push_back(T element);
        T pop_back();
};