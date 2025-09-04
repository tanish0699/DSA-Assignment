#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; 
    return 0;
}
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix ;   

    for (char ch : infix) {      
       
        if ( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ) {
            postfix += ch;        
        }
     
        else if (ch == '(') {     
            st.push(ch);
        }
        
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {   
                postfix += st.top();     
                st.pop();
            }
            st.pop(); 
        }
       
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}