#ifndef SEARCHING2_H
#define SEARCHING2_H

#include "nodes.h" 
#include <iostream>


template <typename T>
bool linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head;  

    while (current != NULL) {
        if (current->data == dataFind) {
            std::cout << "Searching is successful: " << dataFind << " found." << std::endl;
            return true;
        }
        current = current->next;  
    }

    std::cout << "Searching is unsuccessful: " << dataFind << " not found." << std::endl;
    return false;
}

#endif 
