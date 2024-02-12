#pragma once
#include "hash-table.cpp"
#include <bits/stdc++.h>

using namespace std;

struct Node {
    HashTable<char, Node*, 3> children;
    bool valid;

    Node();
};

class LinkedTrie {
    Node* m_root;
    
    public:
        LinkedTrie();
        ~LinkedTrie();
        void clear();
        void insert(const char* str);
        void remove(const char* str);
        int coincidence(const char* str);
        bool search(const char* str);
        bool startWith(const char* prefix);
};