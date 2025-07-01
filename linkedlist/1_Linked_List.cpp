#include <iostream>

using namespace std;

class Node{
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

    int length(){
        int count=0;
        Node *temp = head;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    int sum(){
        int sum;
        Node *temp = head;
        while(temp!=NULL){
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int maximum(){
        int max = INT_MIN;
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data > max)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }

    void linearsearch(int key){
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data == key)
                cout << "Element found at Address: " << temp <<endl;
            
            temp = temp->next;
        }
    }

    void movetohead(int key){
        Node *temp1 = head;
        Node *temp2 = NULL;
        while(temp1!=NULL){
            if(temp1->data == key){
                temp2->next = temp1->next;
                temp1->next = head;
                head = temp1;
                cout << "Element found" <<endl;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    ~linkedlist(){}
};      

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    linkedlist list;
    list.createfromarray(arr,n);
    list.display();

    cout << "Length of Linked List: " << list.length() << endl;
    cout << "Sum of Linked List: " << list.sum() << endl;
    cout << "Maximum element of Linked List: " << list.maximum() << endl;

    int key;
    cout << "Enter search element: ";
    cin >> key;
    list.linearsearch(key);
    list.movetohead(key);
}
