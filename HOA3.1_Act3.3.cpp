#include <iostream>
#include <utility>
using namespace std;

class Node {
public:
    char data;
    Node *next;
    Node *prev;
};



void traverse(Node *head) {
    int ll_count = 1;
    while (head != NULL) {
        cout << "[000" << ll_count << " | " << head->data << " ] ->";
        head = head->next;
        ll_count++;
    }
    cout << " null" << endl; 
}

void insertAtHead(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
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

int main() 
{
        
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *last = new Node;

    head->data = 'C';
    head->next = second;
    second->data = 'P';
    second->next = third;
    third->data = 'E';
    third->next = fourth;
    fourth->data = '0';
    fourth->next = fifth;
    fifth->data = '1';
    fifth->next = last;
    last->data = '0';
    last->next = nullptr;
    
    insertAtHead(head, 'G');
    traverse(head); 

    insertAtPosition(head, 'E' , 3);
    traverse(head); 

    deleteAtPosition(head, 2);
    deleteAtPosition(head, 3);
    
    traverse(head); 

    return 0;
}