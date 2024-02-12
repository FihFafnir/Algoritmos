#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Pair {
    T m_data[2];

    public:
        T& first = m_data[0];
        T& second = m_data[1];

        Pair();
        Pair(T first, T second);
        T& operator[] (size_t index);
};