#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int n) {
        prev = NULL;
        data = n;
        next = NULL;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = NULL;
    }

    void createCircularDoublyfromarray(int arr[], int n) {
        if (n == 0) return;

        head = new Node(arr[0]);
        Node* current = head;
        for (int i = 1; i < n; i++) {
            Node* n = new Node(arr[i]);
            current->next = n;
            n->prev = current;
            current = n;
        }
        current->next = head;
        head->prev = current;
    }

    void displayCircularDoubly() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << "<=>";
            temp = temp->next;
        } while (temp != head);
        cout << "Head" << endl;
    }

    int length() {
        if (head == NULL) return 0;

        int len = 0;
        Node* p = head;
        do {
            len++;
            p = p->next;
        } while (p != head);
        return len;
    }

    void insertCircularDoubly(int pos, int e) {
        if (pos < 0 || pos > length()) return;

        Node* n = new Node(e);
        if (pos == 0) {
            if (head == NULL) {
                head = n;
                head->next = head;
                head->prev = head;
            } else {
                Node* tail = head->prev;
                n->next = head;
                n->prev = tail;
                head->prev = n;
                tail->next = n;
                head = n;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
        }
    }

    void deleteCircularDoubly(int pos) {
        if (pos < 0 || pos >= length()) return;

        if (pos == 0) {
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node* tail = head->prev;
                Node* temp = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete temp;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* d = temp->next;
            temp->next = d->next;
            d->next->prev = temp;
            delete d;
        }
    }

    void reverseCircularDoubly() {
        if (head == NULL) return;

        Node* current = head;
        Node* temp = NULL;
        do {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->prev;
        } while (current != head);
        head = head->prev;
    }
};

int main() {
    int arr[] = {7, 3, 1, 8, 6};
    int n = sizeof(arr) / sizeof(int);

    CircularDoublyLinkedList l;
    l.createCircularDoublyfromarray(arr, n);
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    cout << "\nLength of circular doubly linked list: " << l.length() << endl;

    // -------------------- INSERT --------------------
    cout << "\nInserting 5 at front...\n";
    l.insertCircularDoubly(0, 5);
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    int pos1;
    cout << "\nEnter position to insert: ";
    cin >> pos1;
    cout << "Inserting 2 at given position...\n";
    l.insertCircularDoubly(pos1, 2);
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    // ------------------ DELETE ---------------------
    cout << "\nDeleting at front...\n";
    l.deleteCircularDoubly(0);
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    int pos2;
    cout << "\nEnter position to delete: ";
    cin >> pos2;
    cout << "Deleting at given position...\n";
    l.deleteCircularDoubly(pos2);
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    // ------------------- REVERSE ---------------------
    cout << "\nReversing circular doubly linked list...\n";
    l.reverseCircularDoubly();
    cout << "Displaying circular doubly linked list...\n";
    l.displayCircularDoubly();

    return 0;
}
