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

    void DLLdeleteatfirst(){
        Node *p = head;
        head = head->next;
        delete p;
        if(p!=NULL) p->prev = NULL;
    }

    void DLLdeleteatposition(int pos){
        if(pos<0 || pos>length()) return;
        if(pos==0){
            DLLdeleteatfirst();
            return;
        }
        Node *p = head;
        for(int i=0; i<pos-1; i++)
            p = p->next;
        
        p->prev->next = p->next;
        if(p->next != NULL)
            p->next->prev = p->prev;
        delete p;
    }
};

int main(){
    int arr[] = {4,2,0,12,5,8};
    int n = sizeof(arr) / sizeof(n);

    doublylinkedlist list;
    list.createDLLfromarray(arr,n);
    list.displayDLL();

    cout << "\nDeletion at Begining: " << endl;
    list.DLLdeleteatfirst();
    list.displayDLL();

    cout << "\nDeletion at position: " << endl;
    cout << "Enter the position: ";
    int pos;
    cin >> pos;
    list.DLLdeleteatposition(pos);
    list.displayDLL();
}