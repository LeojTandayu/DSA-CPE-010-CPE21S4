#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(NULL) {}
};


template <typename T>
Node<T>* new_node(T value) {
    return new Node<T>(value);
}


template <typename T>
void displayList(Node<T>* head) {
    Node<T>* currNode = head;
    while (currNode != NULL) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;
}


template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end) {
    if (start == NULL) return NULL;

    Node<T>* slow = start;
    Node<T>* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}


template <typename T>
Node<T>* binarySearch(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* end = NULL;

    while (start != end) {
        Node<T>* mid = getMiddle(start, end);


        if (mid->data == key) {
            return mid;
        }

        else if (mid->data > key) {
            end = mid;
        }

        else {
            start = mid->next;
        }
    }
    return NULL; 
}

int main() {
    char choice = 'y';
    int count = 1, newData;
    Node<int>* temp, *head = NULL, *node = NULL;

    while (choice == 'y') {
        std::cout << "Enter data: ";
        std::cin >> newData;


        if (count == 1) {
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        }

        else if (count == 2) {
            node = new_node(newData);
            head->next = node;
            node->next = NULL;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }


        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
    }


    std::cout << "Linked List: ";
    displayList(head);


    int key;
    std::cout << "Enter value to search: ";
    std::cin >> key;

    Node<int>* result = binarySearch(head, key);
    if (result != NULL) {
        std::cout << "Element " << key << " found in the linked list.\n";
    } else {
        std::cout << "Element " << key << " not found in the linked list.\n";
    }


    temp = head;
    while (temp != NULL) {
        Node<int>* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}
