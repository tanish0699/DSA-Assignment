#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int evaluatePostfix(string postfix) {
    stack<int> st;
for (char ch : postfix) {
        if (!isOperator(ch)) {
            st.push(ch - '0');  
        }
        else {
            int val2 = st.top(); 
            st.pop();
            int val1 = st.top(); 
            st.pop();
if(ch=='+'){
     st.push(val1 + val2); 
     }
else if(ch=='-'){
    st.push(val1 - val2);
     }
else if(ch=='*'){
    st.push(val1 * val2); 
}
    else if (ch=='/')     {
        st.push(val1 / val2);
    }       
                
            }
        }
    

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (digits only): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}