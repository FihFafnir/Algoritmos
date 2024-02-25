#include "hash-table.h"

template <typename K, typename V>
HashTableElement<K, V>::HashTableElement() : key(), value() {}

template <typename K, typename V>
HashTableElement<K, V>::HashTableElement(K key, V value) : key(key), value(value) {}

template <typename K, typename V>
HashTableElement<K, V*>::HashTableElement() : key(), value(nullptr) {}

template <typename K, typename V>
HashTableElement<K, V*>::HashTableElement(K key, V* value) : key(key), value(value) {}

template <typename K, typename V>
HashTableElement<K, V*>::~HashTableElement() {
    delete value;
}

template <typename K, typename V, size_t S>
HashTable<K, V, S>::HashTable() {}

template <typename K, typename V, size_t S>
HashTable<K, V, S>::~HashTable() {
    clear();
}

template <typename K, typename V, size_t S>
size_t HashTable<K, V, S>::hash(const char* key) {
    size_t hash = HASH_CODE;
    size_t c;

    while (c = *key++)
        hash = ((hash << 5) + hash) + c;

    return hash % S;
}

template <typename K, typename V, size_t S>
size_t HashTable<K, V, S>::hash(char key) {
    return (((HASH_CODE << 5) + HASH_CODE) + key) % S;
}

template <typename K, typename V, size_t S>
void HashTable<K, V, S>::clear() {
    for (int i = 0; i < S; i++)
        m_data[i].clear();

}

template <typename K, typename V, size_t S>
void HashTable<K, V, S>::insert(K key, V value) {
    m_data[hash(key)].push_back(new HashTableElement(key, value));
}


template <typename K, typename V, size_t S>
LinkedListElement<HashTableElement<K, V>*>* HashTable<K, V, S>::locate(K key) {
    size_t hashCode = hash(key);
    LinkedListElement<HashTableElement<K, V>*>* iterator = m_data[hashCode].begin();
 
    while (iterator != m_data[hashCode].m_head && iterator->value->key != key)
        iterator = iterator->next;
    return iterator->value->key == key ? iterator : nullptr;
}

template <typename K, typename V, size_t S> 
V HashTable<K, V, S>::remove(K key) {
    LinkedListElement<HashTableElement<K, V>*>* iterator = locate(key);
    if (iterator == nullptr)
        throw runtime_error("Invalid key remove.");
    return m_data[hash(key)].remove(iterator)->value;
}

template <typename K, typename V, size_t S>
bool HashTable<K, V, S>::search(K key) {
    return locate(key) != nullptr;
}

template <typename K, typename V, size_t S>
V& HashTable<K, V, S>::at(K key) {
    LinkedListElement<HashTableElement<K, V>*>* iterator = locate(key);
    if (iterator != nullptr)
        return iterator->value->value;
    throw runtime_error("Invalid key access.");
}

template <typename K, typename V, size_t S>
V& HashTable<K, V, S>::operator[](K key) {
    LinkedListElement<HashTableElement<K, V>*>* iterator = locate(key);
    if (iterator != nullptr)
        return iterator->value->value;
    throw runtime_error("Invalid key access.");
}