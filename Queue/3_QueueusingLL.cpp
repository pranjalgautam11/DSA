#include <iostream>
#include <list>

using namespace std;

class Queue {
private:
    list<int> ll; // Using list to implement the linked list functionality

public:
    // Check if the queue is empty
    bool isEmpty() const {
        return ll.empty();
    }

    // Add an element to the queue
    void enqueue(int value) {
        ll.push_back(value);
        cout << value << " enqueued to queue" << endl;
    }

    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }
        cout << ll.front() << " dequeued from queue" << endl;
        ll.pop_front();
    }

    // Get the front element
    int front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. No front element.");
        }
        return ll.front();
    }

    // Get the rear element
    int rear() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. No rear element.");
        }
        return ll.back();
    }

    // Get the current size of the queue
    int size() const {
        return ll.size();
    }

    // Display the elements of the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (const int& val : ll) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    int choice, val;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Front\n5. Rear\n6. Size\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Queue: ";
                q.display();
                break;
            case 4:
                try {
                    cout << "Front element: " << q.front() << endl;
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try {
                    cout << "Rear element: " << q.rear() << endl;
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                cout << "Size of queue: " << q.size() << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
