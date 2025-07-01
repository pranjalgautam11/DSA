#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int isoperand(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 0;
    return 1;
}

int precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    return 0;
}

string infixtopostfix(string infix){
    stack<char> st;
    string postfix;

    for (char c : infix){
        if(isoperand(c))
            postfix += c;
        else{
            while (!st.empty() && precedence(c) <= precedence(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

int main(){
    cout << "Enter the infix expression: ";
    string infix;
    cin >> infix;

    string postfix = infixtopostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
}