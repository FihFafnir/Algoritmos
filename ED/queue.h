#pragma once
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct QueueElement {
    T value;
    QueueElement<T>* previous;
    QueueElement<T>* next;

    QueueElement();
    QueueElement(T value);
    QueueElement(QueueElement<T>* previous, QueueElement<T>* next);
    QueueElement(T value, QueueElement<T>* previous, QueueElement<T>* next);
};

template<typename T>
class Queue {
    QueueElement<T>* head;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        size_t size();
        T front();
        T back();
        void push(T element);
        T pop();
        void clear();
};