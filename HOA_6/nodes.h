#ifndef NODES_H
#define NODES_H



template <typename T>
class Node {
public:
    T data;          
    Node* next;     

    // Constructor
    Node(T value) : data(value), next(NULL) {} 
};

#endif // NODES_H
