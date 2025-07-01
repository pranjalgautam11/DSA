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
public:
    Node *head1;
    Node *head2;
    Node *temp;
    linkedlist(){
        head1 = NULL;
        head2 = NULL;
        temp = NULL;
    }
    
    void createfromarray1(int arr[], int n){
        if(n==0)
            return;        
            
        head1 = new Node(arr[0]);
        Node *current = head1;
        for(int i=1; i<n; i++){
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }    

    void createfromarray2(int arr[], int n){
        if(n==0)
            return;        
            
        head2 = new Node(arr[0]);
        Node *current = head2;
        for(int i=1; i<n; i++){
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }   

    void display(Node *head){
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

    void concatenating(Node *p, Node *q){
        temp = p;
        while(p->next != NULL) p = p->next;
        p->next = q;
    }

    void merge(Node *p, Node *q){
        if (p == NULL) {
            temp = q;
            return;
        }
        if (q == NULL) {
            temp = p;
            return;
        }

        Node *last = NULL;
        if(p->data < q->data){
            temp = last = p;
            p = p->next;
            temp->next = NULL;
        }
        else{
            temp = last = q;
            q = q->next;
            temp->next = NULL;
        }
        while(p!=NULL && q!=NULL){
            if(p->data < q->data){
                last->next = p;
                last = p;
                p = p->next;
                last->next = NULL;
            }
            else{
                last->next = q;
                last = q;
                q = q->next;
                last->next = NULL;
            }
        }
        if(p!=NULL) last->next = p;
        else last->next = q;
    }
    

    ~linkedlist(){}
};      

int main(){
    int arr1[] = {10,20,30,40,50};
    int arr2[] = {5,15,25,35,45};
    
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    linkedlist list;
    list.createfromarray1(arr1,n1);
    list.display(list.head1);

    list.createfromarray2(arr2,n2);
    list.display(list.head2);

    // list.concatenating(list.head1,list.head2);
    // list.display(list.temp);

    list.merge(list.head1,list.head2);
    list.display(list.temp);
}
