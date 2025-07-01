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

class linkedlist{
private:
    Node *head;
    
public:
    linkedlist(){
        head = NULL;
    }
    
    void createfromarray(int arr[], int n){
        if(n==0)
            return;
            
        head = new Node(arr[0]);
        Node *current = head;

        for(int i=1; i<n; i++){
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }

    void display(){
        if(head==NULL){
            cout << "List is Empty\n";
            return;
        }
        Node *temp = head;
        while(temp!=NULL){
            cout << temp->data  << "->";
            temp = temp->next;
        }
        cout << "Null\n";
    }

    void insertatsorted(int val){
        Node *temp = new Node(val);
        Node *p = head;
        Node *q = NULL;
        if(val < p->data || p == NULL){
            temp->next = head;
            head = temp;
            return;
        }
        while(p!=NULL && p->data < val){
            q = p;
            p = p->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
};

int main(){
    int arr[] = {5,9,15,19,22,29};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    
    int value;
    cout << "Enter the value: ";
    cin >> value;
    list.insertatsorted(value);
    list.display();
}