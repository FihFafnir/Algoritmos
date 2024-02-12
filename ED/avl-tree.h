#pragma once
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
    size_t m_height;
    T m_key;
    Node<T>* m_left;
    Node<T>* m_right;

    public:
        Node(T key);
        void updateHeight();
        friend AVLTree
};

template <typename T>
class AVLTree {
    private:
        Node<T>* m_root;
        Node<T>* rotateToRight(Node<T>* node);
        Node<T>* rotateToLeft(Node<T>* node);
        Node<T>* rotateToLeftAndRight(Node<T>* node);
        Node<T>* rotateToRightAndLeft(Node<T>* node);
    public:
        AVLTree();
};