#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

class doublylinkedlist {
public:
    Node *head;
    doublylinkedlist(){
        head = NULL;
    }

    void createDLLfromarray(int arr[], int n){
        if(n==0) return;

        head = new Node(arr[0]);
        Node *current = head;
        for(int i=1; i<n; i++){
            Node *temp = new Node(arr[i]);
            current->next = temp;
            temp->prev = current;
            current = temp;
        }
    }

    void displayDLL(){
        if(head == NULL)
            return;
        
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int length(){
        int len=0;
        Node *p = head;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        return len;
    }

    void DLLinsertatfirst(int val){
        Node *temp = new Node(val);
        if(head == NULL){
            head = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;        
    }

    void DLLinsertatposition(int pos, int val){
        if(pos<0 || pos>length()) return;
        if(pos==0){
            DLLinsertatfirst(val);
            return;
        }
        Node *temp = new Node(val);
        Node *p = head;
        for(int i=0; i<pos-1; i++)
            p = p->next;
        
        temp->next = p->next;
        if(p->next != NULL)
            p->next->prev = temp;
            
        p->next = temp;
        temp->prev = p;
    }
};

int main(){
    int arr[] = {4,2,0,12,5,8};
    int n = sizeof(arr) / sizeof(n);

    doublylinkedlist list;
    list.createDLLfromarray(arr,n);
    list.displayDLL();

    cout << "\nInsertion at Begining: " << endl;
    int val;
    cout << "Enter the value: ";
    cin >> val;
    list.DLLinsertatfirst(val);
    list.displayDLL();

    cout << "\nInsertion at position: " << endl;
    int pos,val1;
    cout << "Enter the position and value: ";
    cin >> pos >> val1;
    list.DLLinsertatposition(pos,val1);
    list.displayDLL();
}