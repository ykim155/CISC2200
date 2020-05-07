//
//  finalProject.cpp
//  Final Project
//
//  Created by Eugene Kim on 5/7/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

// Function returning operator precedence.
int precedence(char ch);

// Function to check if char is an operand.
bool isOperand(char ch);

// Function to check if char is an operator.
bool isOperator(char ch);

// Function to turn infix notation into prefix.
string infixConvert(string exp);

// Function evaluating the postfix expression.
int postfixEval(string exp);

int main(){
    string exp = "(6 + 13)*2 - (5 + 1)/3";
    cout << infixConvert(exp);
}

int precedence(char ch){
    // If the operator is multiplication or division.
    if(ch == '*' || ch == '/')
        return 2;
    // If the operator is addition or subtraction.
    else if(ch == '+' || ch == '-')
        return 1;
    // Anything else.
    else
        return -1;
}

bool isOperand(char ch){
    // Anything that isn't an operator or parentheses are operands.
    if(isdigit(ch))
        return true;
    else
        return false;
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

string infixConvert(string exp){
    stack<char> s;
    int len = exp.size();
    string postfix;
    for(int i = 0; i < len; i++){
        // If there is a space, ignore.
        if(exp[i] == ' ')
            continue;
        // If we encounter a number.
        else if(isOperand(exp[i])){
            postfix += exp[i];
            // If it's a multi digit number.
            while(isOperand(exp[i+1])){
                postfix += exp[i+1];
                i++;
            }
            postfix += ' ';
        }
        // Push open parenthesis onto stack.
        else if(exp[i] == '(')
            s.push(exp[i]);
        // If we encounter an operator.
        else if(isOperator(exp[i])){
            if(s.empty())
                s.push(exp[i]);
            else if(s.top() == '(')
                s.push(exp[i]);
            else if(precedence(exp[i]) > precedence(s.top()))
                s.push(exp[i]);
            else{
                postfix += s.top();
                s.pop();
                s.push(exp[i]);
                postfix += ' ';
            }
        }
        // If we encounter a closing parenthesis, pop and output until we get to the open parenthesis.
        else if(exp[i] == ')'){
            while(!s.empty()){
                if(s.top() == '('){
                    s.pop();
                    break;
                }
                else{
                    postfix += s.top();
                    s.pop();
                    postfix += ' ';
                }
            }
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
        postfix += ' ';
    }
    return postfix;
}
