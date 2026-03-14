#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Stack{
    public:
        Node *head;
        void Push(char data);
        char Pop();
        char Peek();
        bool isEmpty();
        bool areMatching(char opening, char closing);
        Stack();
};