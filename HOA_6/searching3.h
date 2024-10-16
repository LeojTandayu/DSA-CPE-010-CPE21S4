#ifndef SEARCHING3_H
#define SEARCHING3_H

#include "nodes.h"
#include <iostream>


void linearLS(Node<char>* head, char dataFind) {
    Node<char>* current = head;
    while (current != NULL) {
        if (current->data == dataFind) {
            std::cout << "Search element '" << dataFind << "' is found!" << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Search element '" << dataFind << "' is not found!" << std::endl;
}


template <typename T>
bool binarySearch(T arr[], int n, T item) {
    int low = 0;
    int up = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        if (item == arr[mid]) {
            std::cout << "Search element " << item << " is found!" << std::endl;
            return true; // Item found
        }
        else if (item < arr[mid]) {
            up = mid - 1; // Search in the lower half
        }
        else {
            low = mid + 1; // Search in the upper half
        }
    }

    std::cout << "Search element " << item << " is not found!" << std::endl;
    return false; 
}

#endif 
