#include "graph-adjacency-list.h"

template <size_t S>
void Graph<S>::addEdge(int u, int v) {
    m_data[u].push_back(v);
}

template <size_t S>
bool Graph<S>::areConnected(int u, int v) {
    for (int i = 0; i < m_data[u].size(); i++)
        if (m_data[u][i] == v)
            return true;

    for (int i = 0; i < m_data[u].size(); i++)
        if (areConnected(m_data[u][i], v))
            return true;

    return false;
}