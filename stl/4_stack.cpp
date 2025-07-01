#include <iostream>
#include <stack>

using namespace std;

int main(){
    // DECLARING STACK
    stack<int> st;

    // IS STACK EMPTY 
    cout << "<---Checking if stack empty or not--->" << endl;
    if(st.empty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack is not empty" << endl;
    

    // INSERTING ELEMENT
    cout << "\n<---Inserting element--->" << endl;
    int n, val; 
    cout << "Enter the number of element: ";
    cin >> n;
    for(int i=0; i<n ; i++){
        cout << "Element " << i+1 << ": ";
        cin >> val;
        st.push(val);
    }
    
    // TOP ELEMENT OF STACK
    cout << "\n<---Top element of stack--->" << endl;
    cout << "Top element: " << st.top() << endl;

    // STACK SIZE
    cout << "\nSize of Stack: " << st.size() << endl;

    // POP THE TOP ELEMENT
    cout << "\n<---Popping the element--->" << endl;
    st.pop();
    cout << "Size of Stack after popping: " << st.size() <<endl;
    cout << "Top element after popping: " << st.top() << endl;

    // SWAPPING OF TWO STACK
    stack<int> st1,st2;
    st1.swap(st2);
}