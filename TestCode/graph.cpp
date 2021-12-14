// 通用图的封装

#include<iostream>
#include<vector>
#include<random>
#include "edge.h"
using namespace std;

template<typename T>
class Graph{
    public:
        vector<Node<T>*> nodes;
};


template<typename T>
void PrintGraph(Graph<T>* graph) {
    for (auto x: graph->nodes) {
        cout << "Node Info:" << endl;
        cout << "    value:" << x->value << "    in:"  << x->in << "    out:" <<x-> out << endl;
        for (auto y: x->next) {
            cout << "    " << x->value << "--->" << y->value << endl;
        }
    }
}

Graph<int>* GenRandomIntGraph(int node_num, int next_num) {
    Graph<int>* graph = new Graph<int>();
    for (int i = 0; i < node_num; ++i) {
        Node<int>* node = new Node<int>();
        node->value = i;
        graph->nodes.push_back(node);
    }
    // srand(time(NULL));
    int step = max(node_num / next_num, 1);
    for (int node_index = 0; node_index < node_num; ++node_index) {
        int index = 0;
        for (int i = 0; i < next_num; ++i) {
            index += (rand() + 1) % step;
            if (index != node_index) {
                Node<int>* from_node = graph->nodes[node_index];
                Node<int>* to_node = graph->nodes[index];
                from_node->AddNext(to_node);
            }
        }
    }
    return graph;
}

int main() {
    Graph<int>* graph = GenRandomIntGraph(100, 3);
    PrintGraph<int>(graph);
    return 0;
}