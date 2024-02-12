#include "trie.h"

template <size_t S>
Node<S>::Node() : valid(false) {
    for (int i = 0; i < S; i++)
        children[i] = nullptr;
}

template <size_t S>
Node<S>::~Node() {
    for (int i = 0; i < S; i++)
        if (children[i] != nullptr)
            delete children[i];
}

template <char C, size_t S>
Trie<C, S>::Trie() : m_root(new Node<S>()) {}

template <char C, size_t S>
Trie<C, S>::~Trie() {
    delete m_root;
}

template <char C, size_t S>
void Trie<C, S>::clear() {
    delete m_root;
    m_root = new Node<S>();
}

template <char C, size_t S>
void Trie<C, S>::insert(const char* str) {
    Node<S>* current = m_root;

    for (int i = 0; str[i] != 0; current = current->children[(int) str[i++] - (int) C])
        if (current->children[(int) str[i] - (int) C] == nullptr)
            current->children[(int) str[i] - (int) C] = new Node<S>();
    current->valid = true;
}

template <char C, size_t S>
void Trie<C, S>::remove(const char* str) {
    Node<S>* current = m_root;
    Node<S>* lastValid = nullptr;

    for (int i = 0; str[i] != 0; current = current->children[(int) str[i++] - (int) C])
        if (current->valid)
            lastValid = current;

    for (int i = 0; i < S; lastValid->children[i] = nullptr, i++)
        delete lastValid->children[i];

    current->valid = false;
}

template <char C, size_t S>
int Trie<C, S>::coincidence(const char* str) {
    Node<S>* current = m_root;
    int result = 0;
    for (result = 0; str[result] != 0 && current->children[(int) str[result] - (int) C] != nullptr; result++) 
        current = current->children[(int) str[result] - (int) C];
    return result;
}

template <char C, size_t S>
bool Trie<C, S>::search(const char* str) {
    Node<S>* current = m_root;

    for (int i = 0; str[i] != 0; current = current->children[(int) str[i++] - (int) C])
        if (current->children[(int) str[i] - (int) C] == nullptr)
            return false;
    return current->valid;
}

template <char C, size_t S>
bool Trie<C, S>::startWith(const char* prefix) {
    Node<S>* current = m_root;

    for (int i = 0; prefix[i] != 0; current = current->children[(int) prefix[i++] - (int) C])
        if (current->children[(int) prefix[i] - (int) C] == nullptr)
            return false;
    return true;
}
