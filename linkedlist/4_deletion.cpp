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

    void deleteatfront(){
        Node *p = head;
        head = head->next;
        delete p;
    }

    void deleteatposition(int pos){
        if(pos==1){
            deleteatfront();
            return;
        }
        Node *p = head;
        Node *q = NULL;
        for(int i=0; i<pos-1; i++){
            q = p;
            p = p->next;
        }
        if(p!=NULL){
            q->next = p->next;
            delete p;
        }
    }
};

int main(){
    int arr[] = {5,9,15,19,22,29};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    
    list.deleteatfront();
    list.display();
    
    list.deleteatposition(4);
    list.display();
}