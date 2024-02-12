#pragma once
#include <bits/stdc++.h>

using namespace std;

template <size_t S>
struct Node {
    Node<S>* children[S];
    bool valid;

    Node();
    ~Node();
};

/*
C = First Character
S = Number of Childrens
*/
template <char C, size_t S>
class Trie {
    Node<S>* m_root;
    
    public:
        Trie();
        ~Trie();
        void clear();
        void insert(const char* str);
        void remove(const char* str);
        int coincidence(const char* str);
        bool search(const char* str);
        bool startWith(const char* prefix);
};