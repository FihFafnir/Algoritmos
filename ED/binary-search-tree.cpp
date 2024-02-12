#include "binary-search-tree.h"

template <typename T>
Node<T>::Node(T key) : key(key), left(nullptr), right(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_root(nullptr) {}

template <typename T>
size_t BinarySearchTree<T>::size() {
    return size(m_root);
}

template <typename T>
size_t BinarySearchTree<T>::size(Node<T>* root) {
    return root == nullptr ? 0 : size(root->left) + 1 + size(root->right);
}

template <typename T>
void BinarySearchTree<T>::insert(T element) {
    Node<T>* current = m_root;
    if (current == nullptr)
        m_root = new Node<T>(element);
    else while (current->key != element) 
        if (current->key >= element)
            if (current->left == nullptr)
                current->left = new Node<T>(element);
            else current = current->left;
        else 
            if (current->right == nullptr)
                current->right = new Node<T>(element);
            else current = current->right;
}

template <typename T>
void BinarySearchTree<T>::remove(T element) {
    Node<T>* current = m_root;
    Node<T>* substitute = nullptr;
    Node<T>* parent;
    
    while (current != nullptr && current->key != element) {
        parent = current;
        current = current->key >= element ? current->left : current->right;
    }

    if (current == nullptr)
        return;

    if (current->left != nullptr) {
        substitute = current->left;
        while (substitute->right != nullptr)
            substitute = substitute->right;
    } else if (current->right != nullptr) {
        substitute = current->right;
        while (substitute->left != nullptr)
            substitute = substitute->left;
    }

    if (parent->key >= current->key)
        parent->left = substitute;
    else parent->right = substitute;
    delete current;
}

template <typename T>
bool BinarySearchTree<T>::search(T element) {
    Node<T>* current = m_root;
    while (current != nullptr) {
        if (current->key == element)
            return true;
        current = current->key >= element ? current->left : current->right;
    }
    return false;
}
