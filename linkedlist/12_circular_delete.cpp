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

    void deletecircularatfront(){
        Node *p = head;
        while(p->next!=head) p = p->next;
        if(p==head){
            delete head;
            head = NULL;
        }
        p->next = head->next;
        delete head;
        head = p->next;
    }

    void deletecircularatposition(int pos){
        if(pos<0 || pos>length()) return;
        if(pos==1){
            deletecircularatfront();
            return;
        }
        Node *p = head;
        Node *q = p;
        for(int i=0; i<pos-1; i++)
            p = p->next;
        
        q = p->next;
        p->next = q->next;
        delete q;
    }
};  

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    Circularlinkedlist list;
    list.createcircularfromarray(arr,n);

    cout << "Deleting At front: "<< endl;
    list.deletecircularatfront();
    list.displaycircular();

    int pos;
    cout << "Deleting at given position: " << endl;
    cin >> pos;
    list.deletecircularatposition(pos);
    list.displaycircular();
}