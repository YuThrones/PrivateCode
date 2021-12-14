#include "node.h"

template<class T>
class Edge {
    public:
        Node<T>* from;
        Node<T>* to;
        Edge();
        Edge(Node<T>* from, Node<T>* to) {
            from = from;
            to = to;
        }
};
