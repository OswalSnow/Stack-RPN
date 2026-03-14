#include <iostream>
#include <string>
#include "Node.h"
#include "Stack.h"
using namespace std;

int main(){
    string expression = "2+[5*(1+2+3)]";
    string rpn = "";
    Stack *operators = new Stack();

    for(int i = 0; i < expression.length(); i++){

        if(expression[i] >= '0' && expression[i] <= '9'){
            rpn += expression[i];
        }
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            operators->Push(expression[i]);
        }
        else if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
            operators->Push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
            while(!operators->isEmpty() && !operators->areMatching(operators->Peek(), expression[i])){
                rpn += operators->Pop();
            }
            operators->Pop();
        }
    }

    cout<<"RPN: "<< rpn <<endl;

    while(!operators->isEmpty()){
        rpn += operators->Pop();
    }

    Stack *numbers = new Stack();

    for(int i = 0; i < rpn.length(); i++){
        if(rpn[i] >= '0' && rpn[i] <= '9'){
            numbers->Push(rpn[i]);
        }
        else{
            int b = numbers->Pop() - '0';
            int a = numbers->Pop() - '0';
            int result;

            if(rpn[i] == '+') result = a + b;
            else if(rpn[i] == '-') result = a - b;
            else if(rpn[i] == '*') result = a * b;
            else if(rpn[i] == '/') result = a / b;

            numbers->Push(result + '0');
        }
    }

cout <<"Result: " << numbers->Pop() - '0' << endl;

    return 0;
}