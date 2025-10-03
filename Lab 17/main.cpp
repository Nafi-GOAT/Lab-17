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

struct Node {
    float value;
    Node *next;
};

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

    int entry;
    cout << "Which node to delete? ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    cout << "After which node to insert 10000? ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    deleteList(head);
    output(head);

    return 0;
}

void addFront(Node*& head, float val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void addTail(Node*& head, float val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteNode(Node*& head, int pos) {
    if (!head || pos < 1) return;

    Node* current = head;
    if (pos == 1) {
        head = head->next;
        delete current;
        return;
    }

    Node* prev = nullptr;
    for (int i = 1; i < pos && current; i++) {
        prev = current;
        current = current->next;
    }

    if (prev && current) {
        prev->next = current->next;
        delete current;
    }
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

