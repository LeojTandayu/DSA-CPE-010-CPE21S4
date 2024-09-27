#include <iostream>
#include <utility>
using namespace std;

class Node {
public:
    char data;
    Node *next;
};

void traverse(Node *head) {
    int ll_count = 1;
    while (head != NULL) {
        cout << "[000" << ll_count << " | " << head->data << " ] ->";
        head = head->next;
        ll_count++;
    }
    cout << "null" << endl; 
}

void insertAtHead(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node *&head, char newData, int position) {
    Node *newNode = new Node;
    newNode->data = newData;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds, inserting at end instead." << endl;
        delete newNode; 
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAtTail(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next; 
    }
    
    current->next = newNode;
}

void deleteAtPosition(Node *&head, int position) {
    if (head == nullptr) {
        cout << "List is empty. No nodes to delete." << endl;
        return;
    }

    Node *temp = head;

    if (position == 0) {
        head = temp->next; 
        delete temp;
        return;
    }

    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next; 
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

  
    Node *next = temp->next->next; 
    delete temp->next;
    temp->next = next; 
}


int main() {
    Node *head = nullptr; 

   
    insertAtHead(head, '0');
    insertAtHead(head, '1');

    traverse(head);
    
    insertAtPosition(head, 'X', 0); 
    insertAtPosition(head, 'Y', 2); 

    traverse(head);

    insertAtTail(head, 'A'); 
    insertAtTail(head, 'B'); 
    
    traverse(head); 
    
    deleteAtPosition(head, 2);
    deleteAtPosition(head, 4); 

    traverse(head); 

    return 0;
}
