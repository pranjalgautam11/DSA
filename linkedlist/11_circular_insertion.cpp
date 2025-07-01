#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Circularlinkedlist{
public:
    Node *head;
    Circularlinkedlist(){
        head = NULL;
    }
    
    void createcircularfromarray(int arr[], int n) {
        if(n == 0)
            return;

        head = new Node(arr[0]);
        Node *last = head;  // Initialize last to the head node

        for(int i = 1; i < n; i++) {
            Node *current = new Node(arr[i]);
            last->next = current;
            last = current;
        }
        last->next = head; // Make it circular
    }

    void displaycircular(){
        if(head==NULL) return;
        Node *temp = head;
        do{
            cout << temp->data  << "->";
            temp = temp->next;
        }while(temp!=head);
        cout << "Head\n";
    }

    int length(){
        int len=0;
        Node *p = head;
        do{
            p = p->next;
            len++;
        }while(p != head);
        return len;
    }

    void insertcircularatfirst(int val){
        Node *first = new Node(val);
        Node *p = head;
        if(head==NULL){
            head = first;
            head->next = head;
        }
        else{
            while(p->next != head) p = p->next;
            p->next = first;
            first->next = head;
            head = first;
        }
    }

    void insertcircularatposition(int pos, int val){
        Node *temp = new Node(val);
        Node *p = head;
        if(pos<0 || pos>length()) return;
        if(pos==0){
            insertcircularatfirst(val);
            return;
        }
        for(int i=0; i<pos-1; i++)
            p = p->next;
        
        temp->next = p->next;
        p->next = temp;
    }
};  

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    Circularlinkedlist list;
    list.createcircularfromarray(arr,n);

    cout << "Inserting 5 at front...\n";
    list.insertcircularatfirst(5);
    cout << "Displaying circular linked list...\n";
    list.displaycircular(); 

    int pos;
    cout << "\nEnter position to insert: ";
    cin >> pos;
    cout << "Inserting 2 at given position...\n";
    list.insertcircularatposition(pos,2);
    cout << "Displaying circular linked list...\n";
    list.displaycircular();
}