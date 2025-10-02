//
//  main.cpp
//  Lab 17
//
//  Created by Nafi on 10/1/25.
//
#include <iostream>
using namespace std;

struct Node{
    float value;
    Node *next;
};

void output(Node *hd);
void addFront(Node* head, float val);
void addTail(Node* head, float val);
void deleteNode(Node *head, int pos);
void insertNode(Node* head, int pos,float val);
void deleteList(Node* head);

int main(){
    Node *head = nullptr;
    
    addFront(head, 10);
    addFront(head, 20);
    addTail(head, 99);
    output(head);
    
    deleteNode(head, 2);
    output(head);
    
    insertNode(head, 1, 1000);
    output(head);
    
    deleteList(head);
    output(head);
    
    return 0;
}

void addFront(Node* head, float val){
    Node* newNode = new Node;
    newNode ->value = val;
    newNode->next = head;
    head = newNode;
}

void addTail(Node* head, float val){
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    
    if (!head){
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp ->next)
        temp = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* head, int pos){
    if (!head) return;
    
    Node* current = head;
    Node* prev = nullptr;
    
    for (int i = 1; i < pos && current; i++){
        prev = current;
        current = current ->next;
    }
    
    if (prev && current){
        prev->next = current->next;
        delete current;
    }
}

void insertNode(Node* head, int pos, float val){
    Node* newNode = new Node;
    newNode->value = val;
    
    Node* current = head;
    Node* prev = nullptr;
    
    for (int i = 1; i<pos && current; i++){
        prev = current;
        current = current->next;
    }
    
    newNode ->next = current;
    prev->next = newNode;
}
 
void deleteList(Node* head){
    Node* current = head;
    while (current){
        Node* tmp = current ->next;
        delete current;
        current = tmp;
    }
    head = nullptr;
}

void output(Node * hd){
    if(!hd){
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while(current){
        cout << "["<< count++ << "]" << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
