#include "avl-tree.h"

template <typename T>
Node<T>::Node(T key) : m_key(key), m_left(nullptr), m_right(nullptr), m_height(0) {} 

template <typename T>
void Node<T>::updateHeight() {
    m_height = max(m_left != nullptr ? m_left->m_height : -1, m_right != nullptr ? m_right->m_height : -1) + 1;
} 

template <typename T>
Node<T>* AVLTree<T>::rotateToLeft(Node<T>* node) {
    Node<T>* tmp = node->m_right;
    node->m_right = tmp->m_left;
    tmp->m_left = node;

    node->updateHeight();
    tmp->updateHeight();

    return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::rotateToRight(Node<T>* node) {
    Node<T>* tmp = node->m_left;
    node->m_left = tmp->m_right;
    tmp->m_right = node;

    node->updateHeight();
    tmp->updateHeight();

    return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::rotateToLeftAndRight(Node<T>* node) {
    node->left = rotateToLeft(node->left);
    return rotateToRight(node);
}
template <typename T>
Node<T>* AVLTree<T>::rotateToRightAndLeft(Node<T>* node) {
    node->right = rotateToRight(node->right);
    return rotateToLeft(node);
}
// AVLTree<T>::rotateToRight() : m_root);