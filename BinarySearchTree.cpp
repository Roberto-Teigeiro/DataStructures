#include <iostream>

using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node* prev;

    Node(){}
    Node(int data,Node* prev){this->left=NULL; this->right=NULL; this->data=data; this->prev=prev;}
};


class BinarySearchTree{

    Node* root;
    public:
    BinarySearchTree(int value){this->root=new Node(value,nullptr);};
    void PreOrder(Node* root);
    void InOrder();
    void InOrder(Node* root);
    void PostOrder(Node* root);
    void PostOrder();
    int height(Node* node);
    void ancestors(int key);
    int WhatLevelAmI(Node* node, int key,int count);
    void PreOrder();
    int height();
    Node* BinarySearch(Node* node, int key);
    void Insertion(int value);
    int WhatLevelAmI(int key);
    Node* Insertion(Node* root, int value);
};

Node* BinarySearchTree::Insertion(Node* root, int value){
    if (root == nullptr) {
        root = new Node(value,nullptr);
        return root;
    }
    if(value <= root->data){
        root->left = (root->left==nullptr) ? new Node(value,root) : Insertion(root->left, value);
    }
    else{
        root->right = (root->right==nullptr) ? new Node(value,root) : Insertion(root->right, value);
    }
    return root;
}


void BinarySearchTree::Insertion(int value){
    Insertion(this->root,value);
}
void BinarySearchTree::PreOrder(Node* root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}
void BinarySearchTree::PreOrder(){
    PreOrder(this->root);
}

void BinarySearchTree::InOrder(Node* root){
    if (root==nullptr){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void BinarySearchTree::InOrder(){
    InOrder(this->root);
}


void BinarySearchTree::PostOrder(Node* root){
    if (root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}


void BinarySearchTree::PostOrder(){
    PostOrder(this->root);
}
int BinarySearchTree::height(Node* node){
if (node==nullptr){
return 0;
}

return 1+max(height(node->left),height(node->right));
}

int BinarySearchTree::height(){
return height(this->root);

}

void BinarySearchTree::ancestors(int key){
    cout<<endl<<"Los valores de ancestros son (desde actual->Raiz):";
    Node* temp=BinarySearch(this->root,key);
    while(temp!=nullptr){
        cout<<endl<<temp->data;
        temp=temp->prev;
    }
}

Node* BinarySearchTree::BinarySearch(Node* node, int key){
if(node==nullptr){
    cout<<"No se encontro dicho elemento: "<<endl;
    return NULL;
}

if(key==node->data){
return node;
}

if(key>node->data){
BinarySearch(node->right,key);
}
else{
BinarySearch(node->left,key);
};
}

int BinarySearchTree::WhatLevelAmI(Node* node,int key,int count){

if(node==nullptr){
    return -1;
}

if(key==node->data){
return count;
}

if(key>node->data){
WhatLevelAmI(node->right,key,++count);
}
else{
WhatLevelAmI(node->left,key,++count);
};


}
int BinarySearchTree::WhatLevelAmI(int key){
    return WhatLevelAmI(this->root,key,1);
}

int main(){
BinarySearchTree arbol(1);
arbol.Insertion(58);
arbol.Insertion(88);
arbol.Insertion(45);
arbol.Insertion(17);
arbol.Insertion(7);
arbol.Insertion(3);
arbol.Insertion(51);
arbol.Insertion(63);
arbol.Insertion(46);
arbol.Insertion(1);
arbol.PreOrder();
arbol.WhatLevelAmI(5);

cout<<"La altura es:"<< arbol.WhatLevelAmI(3);
arbol.ancestors(17);
}