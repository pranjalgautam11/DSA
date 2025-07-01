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

    void Inorder(Node* p) {
        if (p != NULL){
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    Node* RSearch(Node* p, int key){
        if(p == NULL) return NULL;
        if(key == p->data) return p;
        else if(key < p->data) return RSearch(p->lchild, key);
        else return RSearch(p->rchild, key);
    }

    Node *Rinsert(Node *p, int key){
        if(p == NULL){
            return new Node(key);
        }
        if(key < p->data)
            p->lchild = Rinsert(p->lchild, key);
        else if(key > p->data)
            p->rchild = Rinsert(p->rchild, key);
        return p;  // Ensure the correct subtree is returned
    }

    int height(Node *p){
        if(p == NULL)
            return 0;
        
        int x = height(p->lchild);
        int y = height(p->rchild);
        return x > y ? x + 1 : y + 1;  // Use 1-based height for comparison
    }

    Node *InPred(Node *p){
        while(p != NULL && p->rchild != NULL)  // Correct logic to find predecessor
            p = p->rchild;
        return p;
    }

    Node *InSucc(Node *p){
        while(p != NULL && p->lchild != NULL)  // Correct logic to find successor
            p = p->lchild;
        return p;
    }

    Node *Rdelete(Node *p, int key){
        Node *temp;
        if(p == NULL)
            return NULL;

        if(p->lchild == NULL && p->rchild == NULL){
            if(p == root)
                root = NULL;
            delete p;
            return NULL;
        }

        if(key < p->data)
            p->lchild = Rdelete(p->lchild, key);
        else if(key > p->data)
            p->rchild = Rdelete(p->rchild, key);
        else{
            if(height(p->lchild) > height(p->rchild)){
                temp = InPred(p->lchild);
                p->data = temp->data;
                p->lchild = Rdelete(p->lchild, temp->data);
            }
            else{
                temp = InSucc(p->rchild);
                p->data = temp->data;
                p->rchild = Rdelete(p->rchild, temp->data);
            }
        }
        return p;
    }
};

int main(){
    BST b;
    
    cout << "Inserting Values...\n";
    b.root = b.Rinsert(b.root, 10);
    b.Rinsert(b.root, 30);
    b.Rinsert(b.root, 3);
    b.Rinsert(b.root, 21);
    b.Rinsert(b.root, 14);
    b.Rinsert(b.root, 26);
    b.Rinsert(b.root, 38);

    cout << "\nInorder traversal...\n";
    b.Inorder(b.root);
    cout << endl;

    cout << "\n\nDeleting values...\n";
    b.Rdelete(b.root, 38);
    b.Rdelete(b.root, 26);
    b.Rdelete(b.root, 10);
    
    cout << "\nInorder traversal...\n";
    b.Inorder(b.root);
    cout << endl;

    cout << "\nSearching...\n";
    Node* temp1 = b.RSearch(b.root, 26);
    if(temp1 != NULL) 
        cout << temp1->data << " found " << endl;
    else 
        cout << "Element not found" << endl;
}
