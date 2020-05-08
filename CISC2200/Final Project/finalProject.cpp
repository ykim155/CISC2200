//
//  finalProject.cpp
//  Final Project
//
//  Created by Eugene Kim on 5/7/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function returning operator precedence.
int precedence(char ch);

// Function to check if char is an operand.
bool isOperand(char ch);

// Function to check if char is an operator.
bool isOperator(char ch);

// Function to turn infix notation into postfix.
string infixConvert(string exp);

// Function evaluating the postfix expression.
int postfixEval(string exp);

// Solve function.
int solve(string exp);

int main(){
    string exp;
    while(true){
        try{
            cout << "Enter an expression (or 'quit' to exit): " << endl;
            getline(cin, exp);
            if(exp == "quit"){
                break;
            }
            int ans = solve(exp);
            cout << exp << " = " << ans << endl;
        }
        catch (char const* msg){
            // Output error message.
            cout << msg << endl;
        }
    }
    return 0;
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
    int const len = exp.size();
    string postfix;
    int openParenthesis = 0;
    if(exp.empty()){
        throw "Error: Please enter an expression.";
    }
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
        else if(exp[i] == '('){
            s.push(exp[i]);
            openParenthesis++;
        }
        // If we encounter an operator.
        else if(isOperator(exp[i])){
            // If the stack is empty or if the top is an open parenthesis, push the operator.
            if(s.empty() || s.top() == '(')
                s.push(exp[i]);
            // If the operator takes precedence comapared to the operator on stack, push the operator.
            else if(precedence(exp[i]) > precedence(s.top()))
                s.push(exp[i]);
            // Else, add the stack's top to output and push the operator.
            else{
                postfix += s.top();
                s.pop();
                s.push(exp[i]);
                postfix += ' ';
            }
        }
        // If we encounter a closing parenthesis, pop and output until we get to the open parenthesis.
        else if(exp[i] == ')'){
            if(openParenthesis == 0)
                throw "Error: Please check your parentheses.";
            while(!s.empty()){
                // If the top is an opening parenthesis, pop and break the loop.
                if(s.top() == '('){
                    s.pop();
                    openParenthesis--;
                    break;
                }
                // Else, push the top of the stack until we encounter an opening parenthesis.
                else{
                    postfix += s.top();
                    s.pop();
                    postfix += ' ';
                }
            }
        }
    }
    // Add leftover operators to the output.
    while(!s.empty()){
        if(s.top() == '(')
            throw "Error: Please check your parentheses.";
        postfix += s.top();
        s.pop();
        postfix += ' ';
    }
    cout << "Postfix expression: " << postfix << endl;
    return postfix;
}

int postfixEval(string exp){
    stack<int> s;
    int const len = exp.size();
    for(int i = 0; i < len; i++){
        // Variable to be used for calculations.
        int num;
        // Ignore spaces.
        if(exp[i] == ' ')
            continue;
        // If we encounter a number.
        else if(isOperand(exp[i])){
            // Multi-digit numbers.
            if(isOperand(exp[i+1])){
                string temp(1, exp[i]);
                while(isOperand(exp[i+1])){
                    temp += exp[i+1];
                    i++;
                }
                num = stoi(temp);
                s.push(num);
            }
            // Single digit numbers.
            else{
                num = exp[i] - '0';
                s.push(num);
            }
        }
        // If we encounter an operator.
        else if(isOperator(exp[i])){
            int op2 = s.top();
            s.pop();
            if(s.empty())
                throw "Error: Please check for dangling operators.";
            int op1 = s.top();
            s.pop();
            switch(exp[i]){
                case '+':
                    num = op1 + op2;
                    break;
                case '-':
                    num = op1 - op2;
                    break;
                case '*':
                    num = op1 * op2;
                    break;
                case '/':
                    if(op2 == 0)
                        throw "Error, division by 0.";
                    num = op1 / op2;
                    break;
            }
            s.push(num);
        }
    }
    return s.top();
}

int solve(string exp){
    return postfixEval(infixConvert(exp));
}
