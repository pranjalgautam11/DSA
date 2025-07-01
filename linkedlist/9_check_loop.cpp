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
public:
    Node *head;
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

    int isloop(Node *head){
        Node *p, *q;
        p = q = head;
        do{
            p = p->next;
            q = q->next;
            if(q != NULL)
                q = q->next;
        }while(p!=NULL && q!=NULL && p!=q);
        if(p==q)
            return 1;
        return 0;
    }
};

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();

    Node *p, *q;
    p = list.head->next;
    q = list.head->next->next->next;
    q->next = p;

    if(list.isloop(p))
        cout << "LL have loop" << endl;
    else
        cout << "LL is linear" << endl;
}