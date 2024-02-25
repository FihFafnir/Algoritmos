#include <bits/stdc++.h>

using namespace std;

template <size_t S>
class Graph {
    int m_data[S+1][S+1];

    public:
        Graph();
        void addVertex(int u);
        void addEdge(int u, int v);
        bool isValidVertex(int u);
        bool areConnected(int u, int v);

};

