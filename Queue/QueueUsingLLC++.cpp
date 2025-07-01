#include <iostream>

using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    
    void enqueue(int x) {
        Node* t = new Node;
        if (t == nullptr){
            cout << "Queue Overflow" << endl;
        } else {
            t->data = x;
            t->next = nullptr;
            if (front == nullptr){
                front = t;
                rear = t;
            } else {
                rear->next = t;
                rear = t;
            }
        }
    }
    
    int dequeue() {
        int x = -1;
        Node* p;
        if (isEmpty()){
            cout << "Queue Underflow" << endl;
        } else {
            p = front;
            front = front->next;
            x = p->data;
            delete p;
        }
        return x;
    }
    
    bool isEmpty() {
        if (front == nullptr){
            return true;
        }
        return false;
    }
    
    ~Queue() {
        Node* p = front;
        while (front){
            front = front->next;
            delete p;
            p = front;
        }
    }
    
    void display() {
        Node* p = front;
        while (p){
            cout << p->data << flush;
            p = p->next;
            if (p != nullptr){
                cout << " <- " << flush;
            }
        }
        cout << endl;
    }
};

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
 
    return 0;
}