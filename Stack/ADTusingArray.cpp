#include <iostream>
#include <limits>
#include <vector>
#include <stack>
using namespace std;

int peek(stack<int> s, int index){
    if (index < 0 || index >= s.size()) return -1;
    stack<int> t = s;
    for(int i=0; i<index; ++i) t.pop();
    return t.top();
}

int isFull(stack<int> s){
    if(s.top()==s.size()-1) return 1;
    else return 0;
}

void display(stack<int> s){
    stack<int> t = s;
    while (!t.empty()) {
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    // PUSHING ELEMENTS
    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;
    int val;
    cout << "Enter " << n <<" elements:\n";
    for(int i=0; i<n ; i++){
        cin >> val;
        st.push(val);
    }

    // CHECK IF EMPTY 
    cout << "\nIs stack empty? " << ((st.empty()) ? "YES" : "NO") << endl;

    // TOP ELEMENT 
    if(!st.empty())
        cout << "\nTop element of stack: " << st.top() << endl;

    // PEEK ELEMENT 
    int p;
    cout << "\nEnter index to peek: ";
    cin >> p; 
    cout << "Element at index " << p << " : " << (peek(st, p)) << endl;

    // CHECK IF FULL
    cout << "\nIs stack full? " << ((isFull(st)) ? "YES" : "NO") << endl;

    // DISPLAYING STACK ELEMENTS
    cout << "\nStack elements:\n";
    display(st);

    // POPPING
    if(!st.empty()) 
        st.pop();
        st.pop();

    cout << "\nStack elements after popping twice:\n";
    display(st);
}