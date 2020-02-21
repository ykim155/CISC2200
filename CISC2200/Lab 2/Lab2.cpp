//
//  Lab2.cpp
//  Lab 2
//
//  Created by Eugene Kim on 2/11/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

string clean(string str); // clean string to have no spaces or punctuation
stack <char> reverse (stack <char> str); // reverse stack
stack <char> stringToStack(string str); // string to vector conversion
void palindrome(string str); // check and output if the string is a palindrome

int main(){
    string str;
    int error = 0;
    do { // to keep trying until user inputs usable string
        try {
            cout << "Enter word or phrase (or 'quit' to exit): ";
            getline(cin, str);
            if (str == "quit"){ // if the user wants to quit, keep going elsewise
                break;
            }
            palindrome(str);
        } catch (char const* msg) {
            cout << msg << endl; // output the error message
            error = 0; // loop again
        }
    } while (error == 0);
}

string clean(string str){
    string clean;
    for (int i = 0; i < str.length(); i++){
        if(isalpha(str[i])){ // if the character at i is alphanumeric
            clean += tolower(str[i]); // add it to the new string
        }
        else if (isdigit(str[i])){ // if the character at i is a number
            clean += str[i];
        }
    }
    return clean;
}

stack <char> stringToStack(string str){
    stack <char> st; // stack to be returned
    for (int i = 0; i < str.length(); i++){ // loop length of string
        st.push(str[i]); // push each letter
    }
    return st;
}

stack <char> reverse(stack <char> original){
    stack <char> reversed; // stack to be returned
    while (!original.empty()){ // while the original stack is not empty
        reversed.push(original.top()); // push top value of stack into new reversed stack
        original.pop(); // pop top value to get to next value
    }
    return reversed;
}

void palindrome(string str){
    bool isPalindrome = true; // bool keeping track of whether or not to move on
    string cleaned = clean(str); // clean string
    stack <char> normal = stringToStack(cleaned); // cleaned string converted to stack
    stack <char> reversed = reverse(normal); // reverse that previous stack
    
    if (normal.empty()){ // catch empty stack exception
        throw "Error: Enter alphanumeric or numeric values.";
    }
    
    while (!normal.empty() && !reversed.empty() && isPalindrome){
        if (normal.top() == reversed.top()){
            normal.pop();
            reversed.pop();
        }
        else{
            isPalindrome = false;
        }
    }
    
    if (isPalindrome){
        cout << "This word or phrase is a palindrome!" << endl;
    }
    else{
        cout << "This word or phrase is not a palindrome." << endl;
    }
}
