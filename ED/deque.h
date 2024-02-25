#pragma once
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct DequeElement {
    DequeElement<T>* next;
    DequeElement<T>* previous;
    T value;

    DequeElement();
    DequeElement(T value);
    DequeElement(DequeElement<T>* previous, DequeElement<T>* next);
    DequeElement(T value, DequeElement<T>* previous, DequeElement<T>* next);
};

template<typename T>
class Deque {
    DequeElement<T>* m_head;

    DequeElement<T>* locate(size_t index);
    DequeElement<T>* locate(size_t index, size_t beginningIndex, DequeElement<T>* ptr);
    public:
        Deque();
        ~Deque();

        bool isEmpty();
        size_t size();

        DequeElement<T>* begin();
        DequeElement<T>* end();

        T& front();
        T& back();
        T& at(size_t index);
        T& operator[](size_t index);

        void insert(size_t index, T element);
        void push_back(T element);
        void push_front(T element);

        T remove(DequeElement<T>* ptr);
        T remove(size_t index);
        T pop_back();
        T pop_front();
        void clear();
        
        void swap(size_t index, size_t anotherIndex);
};