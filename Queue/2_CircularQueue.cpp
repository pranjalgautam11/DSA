#include <iostream>
using namespace std;
 
class CircularQueue{
    private:
        int size;
        int front;
        int rear;
        int* Q;
    public:
        CircularQueue(int size){
            this->size = size;
            front = 0;
            rear = 0;
            Q = new int [size];
        }
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        int frontElement();
        int rearElement();
        void display();
};
 
bool CircularQueue::isEmpty() {
    if (front == rear) return true;
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front) return true;
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()) cout << "\nQueue Overflow\n" << endl;
    else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()) cout << "\nQueue Underflow\n" << endl;
    else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

int CircularQueue::frontElement() {
    return Q[front];
}

int CircularQueue::rearElement() {
    return Q[rear];
}
 
void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << " " << flush;
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}
 
int main() {
    int A[] = {1, 3, 5, 7, 9};
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    cout << "\nENQUEUE...\n";
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++) cq.enqueue(A[i]);

    // Display
    cout << "\nDISPLAY...\n";
    cq.display();
    cout << endl;

    // Is full
    cout << "\nIs full? " << cq.isFull() << endl;

    // Is empty
    cout << "Is empty? " << cq.isEmpty() << endl;

    // Rear
    cout << "\nREAR: " << cq.rearElement() << endl;
 
    // Overflow
    cout << "\nENQUEUE...\n";
    cq.enqueue(10);
 
    // Dequeue
    cout << "\nDEQUEUE...\n";
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++) cout << cq.dequeue() << " ";

    // Is full
    cout << "\nIs full? " << cq.isFull() << endl;

    // Is empty
    cout << "Is empty? " << cq.isEmpty() << endl;

    // Front
    cout << "\nFRONT: " << cq.frontElement() << endl;
 
    // Underflow
    cout << "\nDEQUEUE...\n";
    cq.dequeue();
}