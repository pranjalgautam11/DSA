#include <iostream>
#include <queue>

using namespace std;

int main(){
    // DECLARING QUEUE
    queue<int> q;

    // IS QUEUE EMPTY 
    cout << "<---Checking if queue empty or not--->" << endl;
    if(q.empty())
        cout << "queue is empty!" << endl;
    else
        cout << "queue is not empty" << endl;
    

    // INSERTING ELEMENT
    cout << "\n<---Inserting element--->" << endl;
    int n, val; 
    cout << "Enter the number of element: ";
    cin >> n;
    for(int i=0; i<n ; i++){
        cout << "Element " << i+1 << ": ";
        cin >> val;
        q.push(val);
    }
    
    // Front and back ELEMENT OF queue
    cout << "\n<---Front and back element of queue--->" << endl;
    cout << "front element: " << q.front() << endl;
    cout << "back element: " << q.back() << endl;

    // QUEUE SIZE
    cout << "\nSize of queue: " << q.size() << endl;

    // POP THE TOP ELEMENT
    cout << "\n<---Popping the element--->" << endl;
    q.pop();
    cout << "Size of queue after popping: " << q.size() <<endl;
    cout << "Front element after popping: " << q.front() << endl;
    cout << "Back element after popping: " << q.back() << endl;

    // SWAPPING OF TWO queue
    queue<int> q1,q2;
    q1.swap(q2);
}