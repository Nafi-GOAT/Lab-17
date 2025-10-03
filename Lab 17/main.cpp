//
//  main.cpp
//  Lab 17
//
//  Created by Nafi on 10/1/25.
//
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;

// Node definition
struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node* head);
void addFront(Node*& head, float val);
void addTail(Node*& head, float val);
void deleteNode(Node*& head, int pos);
void insertNode(Node*& head, int pos, float val);
void deleteList(Node*& head);

int main() {
    Node *head = nullptr;

    
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    output(head);

    // Deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);
    output(head);

    // Inserting a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);   // Replaced inline insert with function
    output(head);

    // Deleting the entire linked list
    deleteList(head);
    output(head);

    return 0;
}
    void insertNode(Node*& head, int pos, float val) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = nullptr;

        if (pos <= 1 || !head) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        for (int i = 1; i < pos && current; i++) {
            prev = current;
            current = current->next;
        }

        newNode->next = current;
        if (prev) prev->next = newNode;
    }

    void deleteList(Node*& head) {
        Node* current = head;
        while (current) {
            Node* tmp = current->next;
            delete current;
            current = tmp;
        }
        head = nullptr;
    }

    void output(Node* hd) {
        if (!hd) {
            cout << "Empty list.\n";
            return;
        }
        int count = 1;
        Node* current = hd;
        while (current) {
            cout << "[" << count++ << "] " << current->value << endl;
            current = current->next;
        }
        cout << endl;
    }
