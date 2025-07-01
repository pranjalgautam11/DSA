#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;

        Node(int data){
            this->lchild = NULL;
            this->data = data;
            this->rchild = NULL;
        }
};

class BST{
    public:
        Node* root;
        BST(){ root = NULL; }
        void createFromPreorder(int pre[], int n);
        void Inorder(Node* p);
};

void BST::createFromPreorder(int *pre, int n){
    int i=0;
    root = new Node(pre[i++]);
    Node* temp;
    Node* p=root;
    stack<Node*> s;
    while(i<n){
        if(pre[i]<p->data){
            temp=new Node(pre[i++]);
            p->lchild=temp;
            s.push(p);
            p=temp;
        }
        else{
            while (!s.empty() && pre[i] > s.top()->data) {
                p = s.top();
                s.pop();
            }
            temp = new Node(pre[i++]);
            p->rchild = temp;
            p = temp;
        }
    }
}

void BST::Inorder(Node* p) {
    if (p!=NULL){
        Inorder(p->lchild);
        cout << p->data << " " << flush;
        Inorder(p->rchild);
    }
}

int main(){
    BST b;

    cout << "Generating BST from preorder...\n";
    int pre[] = {30,20,10,15,25,40,50,45};
    int n = sizeof(pre)/sizeof(pre[0]);
    b.createFromPreorder(pre,n);

    cout << "\nInorder traversal...\n";
    b.Inorder(b.root);
    cout << endl;
}
