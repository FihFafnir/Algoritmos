#pragma once
#include <bits/stdc++.h>
#include "linked-list.cpp"
#define HASH_CODE 5381

using namespace std;

template <typename K>
struct HashSetElement {
    K key;

    HashSetElement();
    HashSetElement(K key);
};

template <typename K, size_t S = 17>
class HashSet {
    private:
        LinkedList<HashSetElement<K>*> m_data[S];
        size_t hash(K key);
        LinkedListElement<HashSetElement<K>*>* locate(K key);
    public:
        HashSet();
        void insert(K key);
        void remove(K key);
        bool search(K key);
};
