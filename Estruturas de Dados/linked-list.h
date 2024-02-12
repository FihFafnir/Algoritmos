#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct LinkedListElement {
    T value;
    LinkedListElement<T>* previous;
    LinkedListElement<T>* next;

    LinkedListElement();
    LinkedListElement(T value);
    LinkedListElement(LinkedListElement<T>* previous, LinkedListElement<T>* next);
    LinkedListElement(T value, LinkedListElement<T>* previous, LinkedListElement<T>* next);
};

template <typename T>
struct LinkedListElement<T*> {
    T* value;
    LinkedListElement<T*>* previous;
    LinkedListElement<T*>* next;

    LinkedListElement();
    LinkedListElement(T* value);
    LinkedListElement(LinkedListElement<T*>* previous, LinkedListElement<T*>* next);
    LinkedListElement(T* value, LinkedListElement<T*>* previous, LinkedListElement<T*>* next);
};

template <typename T>
class LinkedList {
    LinkedListElement<T>* m_head;
    LinkedListElement<T>* begin();
    LinkedListElement<T>* end();
    LinkedListElement<T>* locate(size_t index);

    T remove(LinkedListElement<T>* ptr);

    public:
        LinkedList();
        ~LinkedList();

        bool isEmpty();
        size_t size();
        void clear();

        T& front();
        T& back();
        T& at(size_t index);
        T& operator[](size_t index);

        void push_front(T value);
        void push_back(T value);
        void insert(size_t index, T value);

        T remove(size_t index);
        T pop_front();
        T pop_back();

        void swap(size_t index, size_t anotherIndex);

        template <typename K, typename V, size_t S>
        friend class HashTable;
        template <typename K, size_t S>
        friend class HashSet;
};

template <typename T>
class LinkedList<T*> {
    LinkedListElement<T*>* m_head;
    LinkedListElement<T*>* begin();
    LinkedListElement<T*>* end();
    LinkedListElement<T*>* locate(size_t index);

    T* remove(LinkedListElement<T*>* ptr);

    public:
        LinkedList();
        ~LinkedList();

        bool isEmpty();
        size_t size();
        void clear();

        T& front();
        T& back();
        T& at(size_t index);
        T& operator[](size_t index);

        void push_front(T* value);
        void push_back(T* value);
        void insert(size_t index, T* value);

        T* remove(size_t index);
        T* pop_front();
        T* pop_back();

        void swap(size_t index, size_t anotherIndex);

        template <typename K, typename V, size_t S>
        friend class HashTable;
        template <typename K, size_t S>
        friend class HashSet;
};
