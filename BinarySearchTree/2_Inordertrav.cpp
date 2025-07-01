#include <iostream>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int data){
        this->lchild = NULL;
        this->data = data;
        this->rchild = NULL;
    }
};

class BST{
public:
    Node *root;
    BST(){
        root = NULL;
    }

    void insert(int key){
        Node *temp = root;
        Node *p;
        Node *tail;
        if(root==NULL){
            p = new Node(key);
            root = p;
            return;
        }
        while(temp!=NULL){
            tail = temp;
            if(key<temp->data)
                temp = temp->lchild;
            else if(key>temp->data)
                temp = temp->rchild;
            else
                return;
        }
        p = new Node(key);
        if(key<tail->data)
            tail->lchild = p;
        else
            tail->rchild = p;
    }

    Node* search(int key){
        Node *temp = root;
        while(temp!=NULL){
            if(key==temp->data) return temp;
            else if(key<temp->data) temp = temp->lchild;
            else temp = temp->rchild;
        }
        return NULL;
    }

    void inorder(Node *p){
        if(p){
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }

    }
};

int main(){
    BST b;
    
    cout << "Inserting Values...\n";
    b.insert(10);
    b.insert(30);
    b.insert(3);
    b.insert(25);
    b.insert(14);

    cout << "\nInorder traversal...\n";
    b.inorder(b.root);
    cout << endl;
}
