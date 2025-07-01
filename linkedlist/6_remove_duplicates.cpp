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

    void removeduplicatessorted(){
        Node* temp = head;
        while(temp != NULL && temp->next != NULL) {
            if(temp->data == temp->next->data){
                Node* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } 
            else {
                temp = temp->next; // Only move to the next node if no deletion occurred
            }
        }
    }
};

int main(){
    int arr[] = {1,2,3,4,4,5,6,6,6,7,9};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    
    list.removeduplicatessorted();
    list.display();
}