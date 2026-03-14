#include "Stack.h"
#include "Node.h"

Stack::Stack(){
    head = nullptr;
}

bool Stack::isEmpty(){
    return head == nullptr;
}

void Stack::Push(char data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

char Stack::Pop(){
    if(isEmpty()){
        cout<<"Error: The stack is already empty"<<endl;
        return '\0';
    }
    Node *temp = head;
    char data = temp->data;
    head = temp->next;
    delete temp;

    return data;
}

char Stack::Peek(){
    if(isEmpty()){
        cout<<"The stack is empty"<<endl;
        return '\0';
    }
    return head->data;
}

bool Stack::areMatching(char opening, char closing){
    if(opening == '(' && closing == ')') return true;
    if(opening == '[' && closing == ']') return true;
    if(opening == '{' && closing == '}') return true;
    return false;
}
