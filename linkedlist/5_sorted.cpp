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

    int issorted(){
        Node *temp = head;
        int min = INT_MIN;
        while(temp != NULL && temp->next != NULL){
            if(temp->data > temp->next->data)
                return 0;

            temp = temp->next;
        }
        return 1;
    }
};

int main(){
    int arr[] = {5,9,11,19,22,29};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    
    if(list.issorted())
        cout << "List is sorted" << endl;
    else
        cout << "List is not sorted" << endl;
}