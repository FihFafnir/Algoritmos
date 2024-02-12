#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct StackElement {
    T value;
    StackElement<T>* next;
    
    StackElement();
    StackElement(T value);
    StackElement(StackElement<T>* next);
    StackElement(T value, StackElement<T>* next);
};

template <typename T>
class Stack {
    StackElement<T>* m_top;
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        size_t size();
        void push(T element);
        T pop();
        T top();
        void clear();
};
