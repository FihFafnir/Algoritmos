#pragma once
#include <bits/stdc++.h>
#include "linked-list.cpp"
#define HASH_CODE 5381

using namespace std;

template <typename K, typename V>
struct HashTableElement {
    K key;
    V value;

    HashTableElement();
    HashTableElement(K key, V value);
};

template <typename K, typename V>
struct HashTableElement<K, V*> {
    K key;
    V* value;

    HashTableElement();
    HashTableElement(K key, V* value);
    ~HashTableElement();
};

template <typename K, typename V, size_t S = 17>
class HashTable {
    private:
        LinkedList<HashTableElement<K, V>*> m_data[S];
        // size_t hash(K key);
        size_t hash(const char* key);
        size_t hash(char key);
        LinkedListElement<HashTableElement<K, V>*>* locate(K key);
    public:
        HashTable();
        ~HashTable();
        void clear();
        bool search(K key);
        void insert(K key, V value);
        V remove(K key);
        V& at(K key);
        V& operator[](K key);
};