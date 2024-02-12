#include "generic-tree.h"

template <typename T>
Node<T>::Node(T key) : key(key), adjacent(nullptr), child(nullptr) {}

template <typename T>
GenericTree<T>::GenericTree() : m_root(nullptr) {}

template <typename T>
bool GenericTree<T>::isValidNode(Node<T>* node, Node<T>* root) {
    return root == node ? true : (
            root == nullptr ? false : 
            isValidNode(node, root->child) | isValidNode(node, root->adjacent)
    );
}

template <typename T>
bool GenericTree<T>::isValidNode(Node<T>* node) {
    return isValidNode(node, m_root);
}

template <typename T>
void GenericTree<T>::insert(Node<T>* root, T element) {

}

