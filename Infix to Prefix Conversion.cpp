#include <iostream>
#include <stack>
#include <string>
#include <algorithm> 

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            operators.push(c);
        }
       
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }

        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}


string infixToPrefix(const string& infix) {
    
    string reversedInfix = string(infix.rbegin(), infix.rend());
    '(' with ')' and vice versa
    for (char &c : reversedInfix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

  
    string postfix = infixToPostfix(reversedInfix);

    string prefix = string(postfix.rbegin(), postfix.rend());
    
    return prefix;
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
