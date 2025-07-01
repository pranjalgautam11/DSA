#include <iostream>
#include <queue>

using namespace std;

int isfull(queue<int> q, int size){
    return q.size()==size;
}

void display(queue<int> q){
    queue<int> t = q;
    while(!t.empty()){
        cout << t.front() << " ";
        t.pop();
    }
}

int main(){
    // DECLARING QUEUE
    queue<int> q;

    // SIZE and Insertion
    int n, val; 
    cout << "Enter the size of queue: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Element " << i+1 << ": ";
        cin >> val;
        q.push(val);
    }
    
    // IS QUEUE EMPTY 
    cout << "<---IS QUEUE EMPTY?--->" << endl;
    if(q.empty())
        cout << "YES!" << endl;
    else
        cout << "NO!" << endl;

    // IS QUEUE FULL 
    cout << "<---IS QUEUE FULL?--->" << endl;
    if(isfull(q,n))
        cout << "YES!" << endl;
    else
        cout << "NO!" << endl;
    
    // Front and back ELEMENT OF queue
    cout << "\n<---Front and back element of queue--->" << endl;
    cout << "front element: " << q.front() << endl;
    cout << "back element: " << q.back() << endl;

    // QUEUE SIZE
    cout << "\nSize of queue: " << q.size() << endl;

    // Displaying Queue
    cout << "QUEUE: ";
    display(q);

    // POP THE TOP ELEMENT
    cout << "\n\n<---Popping the element--->" << endl;
    q.pop();
    cout << "Size of queue after popping: " << q.size() <<endl;
    cout << "Front element after popping: " << q.front() << endl;
    cout << "Back element after popping: " << q.back() << endl;

}