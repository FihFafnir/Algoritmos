#include "graph-adjacency-list.cpp"

using namespace std;


int main(int argc, char** argv) {
    Graph<10> g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 4);

    cout << g.areConnected(1, 2) << endl;
    cout << g.areConnected(1, 3) << endl;
    cout << g.areConnected(1, 4) << endl;

    return 0;
}