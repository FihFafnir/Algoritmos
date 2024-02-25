#include <bits/stdc++.h>
#include "vector.cpp"

template <size_t S>
class Graph {
    Vector<int> m_data[S+1];
    
    public:
        void addEdge(int u, int v);
        bool areConnected(int u, int v);
};