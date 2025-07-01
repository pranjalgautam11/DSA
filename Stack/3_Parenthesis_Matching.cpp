#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isbalanced(string str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(st.empty())
                return false;
            
            char top = st.top();
            st.pop();
            if(str[i] == ')' && top != '()'
            || str[i] == ']' && top != '['
            || str[i] == '}' && top != '{')
                return false;
        }
    }
    return st.empty();
}

int main(){
    cout << "Enter the expression: ";
    string input;
    cin >> input;

    if(isbalanced(input))
        cout << "Expression contains Balanced Parenthesis";
    else
        cout << "Expression contains Balanced Parenthesis";
}