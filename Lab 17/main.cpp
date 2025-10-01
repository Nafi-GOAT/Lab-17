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
