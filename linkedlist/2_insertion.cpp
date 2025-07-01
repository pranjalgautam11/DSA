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

    void insertatfirst(int val){
        Node *first = new Node(val);
        first->next = head; 
        head = first;
    }

    void insertatposition(int pos, int val){
        if(pos==0){
            insertatfirst(val);
            return;
        }
        Node *p = new Node(val);
        Node *temp = head;
        for(int i=0; i<pos-1; i++)
            temp = temp->next;
        
        p->next = temp->next;
        temp->next = p;
    }

    void insertatend(int val){
        Node *p = new Node(val);
        if(head == NULL)
            head = p;
        else{
            Node *temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            
            temp->next = p;
        }
    }
};

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    int value;
    cout << "Enter the value for new node to insert at first position: ";
    cin >> value;
    list.insertatfirst(value);
    list.display();

    int pos, val;
    cout << "Enter the position and value to insert in the linked list: ";
    cin >> pos >> val;
    list.insertatposition(pos,val);
    list.display();

    int lastval;
    cout << "Enter the value of last node: ";
    cin >> lastval;
    list.insertatend(lastval);
    list.display();

    // CREATING LL WITH INSERT FUNCTIONS

    cout << "\n LL with insert functions \n";
    linkedlist ll;
    ll.insertatposition(0,3);
    ll.insertatposition(1,5);
    ll.insertatposition(2,10);
    ll.insertatposition(3,2);
    ll.display();

    ll.insertatend(4);
    ll.insertatend(11);
    ll.insertatend(8);
    ll.display();
}