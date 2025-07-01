#include <iostream>
#include <vector>

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

    void reversing(){
        vector<int> v;
        Node *temp = head;
        int i=0;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
            i++;
        }
        Node *temp1 = head;
        i--;
        while(temp1!=NULL){
            temp1->data = v[i--];
            temp1 = temp1->next;
        }
    }

    void reversinglinks(){
        Node *p = head;
        Node *q = NULL;
        Node *r = NULL;
        while(p!=NULL){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }
};

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    linkedlist list;
    list.createfromarray(arr,n);
    list.display();
    
    list.reversing();
    list.display();

    list.reversinglinks();
    list.display();
}