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
    output (head);
    
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
    newNode ->value = val;
    newNode->next = nullptr;
    
    if  (!head){
        head = newNode;
        return;
        
    }
    
    Node* temp = head;
    while (temp ->next)
        temp = temp ->next;
    temp ->next = newNode;
}

