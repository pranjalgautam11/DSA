#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class linkedlist {
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

    int middleelement(){
        Node *p = head;
        Node *q = head;
        while(p->next != NULL){
            p = p->next->next;
            q = q->next;
        }
        return q->data;
    }

    ~linkedlist(){}
};      

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    linkedlist list;
    list.createfromarray(arr,n);
    list.display();

    cout << "Middle element is: " << list.middleelement();
}
