#include<vector>

template<class T>
class Edge;

template<class T>
class Node {
    public:
        int in = 0;
        int out = 0;
        T value;
        std::vector<Node<T>*> next;
        std::vector<Edge<T>*> edge;

        Node<T>() {}
        Node<T>(T value) {
            value = value;
        }
        void AddNext(Node<T>* next_node) {
            next.push_back(next_node);
            out++;
            next_node->in++;
            Edge<T>* new_edge = new Edge<T>(this, next_node);
            edge.push_back(new_edge);
            next_node->edge.push_back(new_edge);
        }
};
