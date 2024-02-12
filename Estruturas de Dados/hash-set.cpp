#include "hash-set.h"

template <typename K>
HashSetElement<K>::HashSetElement() : key() {}

template <typename K>
HashSetElement<K>::HashSetElement(K key) : key(key) {}

template <typename K, size_t S>
HashSet<K, S>::HashSet() {}

template <typename K, size_t S>
size_t HashSet<K, S>::hash(K key) {
    return ((5381 << 5) + 5381 + key) % S;
}

template <typename K, size_t S>
void HashSet<K, S>::insert(K key) {
    m_data[hash(key)].push_back(new HashSetElement(key));
}

template <typename K, size_t S>
LinkedListElement<HashSetElement<K>*>* HashSet<K, S>::locate(K key) {
    size_t hashCode = hash(key);
    LinkedListElement<HashSetElement<K>*>* iterator = m_data[hashCode].begin();
 
    while (iterator != m_data[hashCode].m_head && iterator->value->key != key)
        iterator = iterator->next;
    return iterator->value->key == key ? iterator : nullptr;
}

template <typename K, size_t S> 
void HashSet<K, S>::remove(K key) {
    LinkedListElement<HashSetElement<K>*>* iterator = locate(key);
    if (iterator != nullptr) 
        m_data[hash(key)].remove(iterator);
}

template <typename K, size_t S>
bool HashSet<K, S>::search(K key) {
    return locate(key) != nullptr;
}