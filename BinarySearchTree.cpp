#include <iostream>

using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node* prev;

    Node(){}
    Node(int data){this->left=NULL; this->right=NULL; this->data=data; this->prev=NULL;}
};


class BinarySearchTree{

    Node* root;
    public:
    BinarySearchTree(int value){this->root=new Node(value);};
    void PreOrder(Node* root);
    void InOrder();
    void InOrder(Node* root);
    void PostOrder(Node* root);
    void PostOrder();
    void LevelByLevel();
    int height(int height);
    void ancestors();
    int WhatLevelAmI();
    void PreOrder();
    void Insertion(int value);
    Node* Insertion(Node* root, int value);
};

Node* BinarySearchTree::Insertion(Node* root, int value){
    if (root == nullptr) {
        root = new Node(value);
        return root;
    }
    if(value <= root->data){
        root->left = (root->left==nullptr) ? new Node(value) : Insertion(root->left, value);
    }
    else{
        root->right = (root->right==nullptr) ? new Node(value) : Insertion(root->right, value);
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
int BinarySearchTree::height(int height){

return 1;


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

}