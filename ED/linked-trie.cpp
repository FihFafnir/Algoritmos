#include "linked-trie.h"

Node::Node() : valid(false) {}

LinkedTrie::LinkedTrie() : m_root(new Node()) {}

LinkedTrie::~LinkedTrie() {
    delete m_root;
}

void LinkedTrie::clear() {
    delete m_root;
    m_root = new Node();
}

void LinkedTrie::insert(const char* str) {
    Node* current = m_root;
    for (int i = 0; str[i] != 0; current = current->children[str[i++]])
        if (!current->children.search(str[i]))
            current->children.insert(str[i], new Node());
    current->valid = true;
}

void LinkedTrie::remove(const char* str) {
    // Node* current = m_root;
    // Node* lastValid = nullptr;

    // for (int i = 0; str[i] != 0; current = current->children[(int) str[i++] - (int) C])
    //     if (current->valid)
    //         lastValid = current;

    // for (int i = 0; i < S; lastValid->children[i] = nullptr, i++)
    //     delete lastValid->children[i];

    // current->valid = false;
}

int LinkedTrie::coincidence(const char* str) {
    Node* current = m_root;
    int result = 0;
    for (result = 0; str[result] != 0 && current->children.search(str[result]); result++) 
        current = current->children[str[result]];
    return result;
}

bool LinkedTrie::search(const char* str) {
    Node* current = m_root;

    for (int i = 0; str[i] != 0; current = current->children[str[i++]])
        if (!current->children.search(str[i]))
            return false;
    return current->valid;
}

bool LinkedTrie::startWith(const char* prefix) {
    Node* current = m_root;

    for (int i = 0; prefix[i] != 0; current = current->children[prefix[i++]])
        if (!current->children.search(prefix[i]))
            return false;
    return true;
}
