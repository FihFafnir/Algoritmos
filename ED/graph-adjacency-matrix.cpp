#include "graph-adjacency-matrix.h"

template <size_t S>
Graph<S>::Graph() {
    memset(m_data, 0, sizeof(m_data));
}

template <size_t S>
void Graph<S>::addVertex(int u) {
    if (u <= S)
        m_data[u][u] = 1;
}

template <size_t S>
void Graph<S>::addEdge(int u, int v) {
    if (isValidVertex(u) && isValidVertex(v))
        m_data[u][v] = 1;
}

template <size_t S>
bool Graph<S>::isValidVertex(int u) {
    return u <= S && m_data[u][u];
}

template <size_t S>
bool Graph<S>::areConnected(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v))
        return false;

    if (m_data[u][v])
        return true;

    for (int w = 0; w <= S; w++)
        if (u != w && m_data[u][w] && areConnected(w, v)) 
            return true;
    return false;
}