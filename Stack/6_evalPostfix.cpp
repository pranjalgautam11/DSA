#include <iostream>
#include <stack>
#include <string>
using namespace std;

int isOperand(char e){
    if(e=='+'||e=='-'||e=='*'||e=='/') return 0;
    else return 1;
}

int evaluatePostfix(string exp){
    stack<int> s;
    int x1,x2,r;
    for(char c:exp){
        if(isOperand(c)) s.push(c-'0');
        else{
            x2=s.top();
            s.pop();
            x1=s.top();
            s.pop();
            switch(c){
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;
            }
            s.push(r);
        }
    }
    return s.top();
}

int main(){
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    if(result!=-1) cout<< "Value of expression is: " << result <<endl;
}