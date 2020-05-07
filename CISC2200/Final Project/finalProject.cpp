//
//  finalProject.cpp
//  Final Project
//
//  Created by Eugene Kim on 5/7/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

// Function returning operator precedence.
int precedence(char ch);

// Function to turn infix notation into prefix.
void infixConvert(string exp);

// Function evaluating the postfix expression.
int postfixEval(stack<char> exp);

int main(){
    
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
