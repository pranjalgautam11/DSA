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

    void display(){
        if(head==NULL) return;
        Node *temp = head;
        do{
            cout << temp->data  << "->";
            temp = temp->next;
        }while(temp!=head);
        cout << "Head\n";
    }

};

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    Circularlinkedlist list;
    list.createcircularfromarray(arr,n);
    list.display();
}