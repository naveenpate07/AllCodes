#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    int height;
    Node(int value) : data(value) , left(nullptr),right(nullptr),height(1) {}
};
class AVL{
    private:
    Node*root;
    public:
    AVL() : root(nullptr) {}
    Node*rightRotate(Node*root){
        Node*second=root->left;
        Node*temp=second->right;
        second->right=root;
        root->left=temp;
        root->height=1+max(height(root->left),height(root->right));
        second->height=1+max(height(second->left),height(second->right));
        return second;
    }
    Node*leftRotate(Node*root){
        Node*second=root->right;
        Node*temp=second->left;
        second->left=root;
        root->right=temp;
         root->height=1+max(height(root->left),height(root->right));
        second->height=1+max(height(second->left),height(second->right));
        return second;
    }
    int height(Node*root){
        return root ? root->height : 0;
    }
    int balanceFactor(Node*root){
        return root ? (height(root->left) - height(root->right)) : 0;
    }
    Node* insert(Node*root,int value){
        if(root==nullptr) {
            return new Node(value);
        }
        if(value < root->data){
            root->left=insert(root->left,value);
        }else if(value > root->data){
            root->right=insert(root->right,value);
        }else return root;
        
        root->height=1+max(height(root->left) , height(root->right));
        int bfactor=balanceFactor(root);
        // right rotate
        if(bfactor > 1 && value < root->left->data){
            return rightRotate(root);
        }
        // leftRotate
        if(bfactor < -1 && value > root->right->data){
            return leftRotate(root);
        }
        // right left rotate
        if(bfactor < -1 && value < root->right->data){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        if(bfactor > 1 && value > root->left->data){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        return root;
    }
    void insert(int value){
        root=insert(root,value);
    }
    void display(Node*root){
        if(root==nullptr) return;
        cout<<root->data<<" ";
        display(root->left);
        
        display(root->right);
    }
    void display(){
        display(root);
    }
};
int main(){
    AVL a;
    a.insert(5);
    a.insert(10);
    a.insert(15);
    a.display();
    return 0;
}