#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    Node<T>* adjacent;
    Node<T>* child;
    T key;

    Node(T key);
};

template <typename T>
class GenericTree {
    Node<T>* m_root;

    public:
        GenericTree();
        bool isValidNode(Node<T>* node);
        bool isValidNode(Node<T>* node, Node<T>* root);
        void insert(Node<T>* root, T element);
};