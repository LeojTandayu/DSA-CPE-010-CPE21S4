#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>  


template <typename T>
bool linearSearch(T data[], int n, T item) {
    for (int i = 0; i < n; i++) {
        if (data[i] == item) {
            std::cout << "Searching is successful. Item found at index " << i << std::endl;
            return true;
        }
    }
    std::cout << "Searching is unsuccessful. Item not found in the array." << std::endl;
    return false;
}

#endif 
