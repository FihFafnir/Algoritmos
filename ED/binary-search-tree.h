#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    Node<T>* left;
    Node<T>* right;
    T key;
    
    Node(T key);
};

template <typename T>
class BinarySearchTree {
    Node<T>* m_root;

    public:
        BinarySearchTree();
        size_t size();
        size_t size(Node<T>* root);
        void insert(T element);
        void remove(T element);
        bool search(T element);
};