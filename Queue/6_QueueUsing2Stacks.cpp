#include <iostream>
#include <stack>
#include <vector>

using namespace std;
 
class Queue{
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    void enqueue(int x) {
        stk1.push(x);
    }
    
    int dequeue() {
        int x = -1;
        if (stk2.empty()){
            if (stk1.empty()){
                cout << "Queue Underflow" << endl;
                return x;
            } else {
                while (!stk1.empty()){
                    stk2.push(stk1.top());
                    stk1.pop();
                }
            }
        }
        x = stk2.top();
        stk2.pop();
        return x;
    }
};
 
 
int main() {
 
    vector<int> v = {1,3,5,7,2,10};
 
    Queue q;
 
    cout << "Enqueue: " << endl;
    for (int i=0; i<v.size(); i++){
        q.enqueue(v[i]);
        cout << v[i];
        if (i < v.size()-1){
            cout << " <- ";
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << q.dequeue();
        if (i < v.size()-1){
            cout << " <- ";
        }
    }
 
    return 0;
}