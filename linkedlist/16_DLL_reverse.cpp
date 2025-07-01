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

    void reverseDLL(){
        Node *p = head;
        Node *temp = NULL;
        while(p != NULL){
            temp = p->prev;
            p->prev = p->next;
            p->next = temp;
            p = p->prev;
            if(temp != NULL)
                head = temp->prev;
        }
    }
};

int main(){
    int arr[] = {4,2,0,12,5,8};
    int n = sizeof(arr) / sizeof(n);

    doublylinkedlist list;
    list.createDLLfromarray(arr,n);
    list.displayDLL();

    cout << "Reversing DLL: "<< endl;
    list.reverseDLL();
    list.displayDLL();
}