#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T, size_t S>
class Array {
    T m_data[S];

    public:
        Array();
        Array(T& element, ...);
        Array(T (&arr)[S]);
        bool is_empty();
        size_t size();
        T* data();
        T& operator[](size_t index);
        T& at(size_t index);
        T& front();
        T& back();
        void fill(T element);
        void swap(size_t index, size_t anotherIndex);
};
