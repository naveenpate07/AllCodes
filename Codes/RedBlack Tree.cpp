#include<bits/stdc++.h>
using namespace std;
enum color {red,black};
struct Node{
    int data;
    Node*left;
    Node*right;
    Node*parent;
    bool col;
    Node(int value) : data(value) , left(nullptr) , right(nullptr) , col(red),parent(nullptr){}
};
class RedBlackTree{
    private:
    Node*root;
    public:
    RedBlackTree() : root(nullptr) {}
    void leftRotate(Node*root,Node*first){
        Node*second=first->right;
        first->right=second->left;
        if(second->left!=nullptr) second->left->parent=first;
        second->parent=first->parent;
        if(first->parent==nullptr) root=second;
        else if(first==first->parent->left) first->parent->left=second;
        else first->parent->right=second;
        first->parent=second;
        second->left=first;
    }
    void rightRotate(Node*root,Node*first){
        Node*second=first->left;
        first->left=second->right;
        if(second->right!=nullptr){
            second->right->parent=first;
        }
        second->parent=first->parent;
        if(first->parent==nullptr) root=second;
        else if(first==first->parent->left) first->parent->left=second;
        else first->parent->right=second;
        first->parent=second;
        second->right=first;
    }
    void fixTree(Node*node,Node*root){
        Node*parent=nullptr;
        Node*gparent=nullptr;
        while(node!=root && node->parent==red && node->parent->parent==red){
            parent=node->parent;
            gparent=node->parent->parent;
            // check it where parent is present (left or right)
            if(parent==gparent->left){
                Node*uncle=gparent->right;
                if(uncle && uncle->col==red){
                    uncle->col=black;
                    parent->col=black;
                    gparent->col=red;
                    node=parent;
                }
                else{
                    // check we need do left roatate or not
                    if(node==parent->right){
                        leftRotate(root,parent);
                        node=parent;
                        parent=node->parent;
                    }
                    rightRotate(root,gparent);
                    swap(gparent->col,parent->col);
                    node=parent;
                }
            }else{
                Node*uncle=gparent->left;
                if(uncle && uncle->col== red){
                    gparent->col=red;
                    uncle->col=black;
                    parent->col=black;
                    node=parent;
                }else{
                    // find we do right rotate or not
                    if(node==parent->left){
                        rightRotate(root,parent);
                        node=parent;
                        parent=node->parent;
                    }
                    leftRotate(root,gparent);
                    swap(parent->col,gparent->col);
                    node=parent;
                }
            }
        }
        root->col=black;
    }
    void insert(Node*root,int value){
        Node*temp=root;
        Node*parent=nullptr;
        while(temp){
            parent=temp;
            if(temp->data > value){
                temp=temp->left;
            }else temp=temp->right;
        }
        Node*newnode= new Node(value);
        newnode->parent=parent;
        if(parent->data > value){
            parent->left=newnode;
        }else parent->right=newnode;
        fixTree(newnode,root);
    }
    void insert(value){
        if(root==nullptr) {
            root=new Node(value);
            return ;
        }
        insert(root,value);
    }
    void display(Node*root){
        display(root->left);
        cout<<root->data<<"("<<root->col<<")"<<" , ";
        display(root->right);
    }
    void display(){
        display(root);
    }
};
int main(){
    RedBlackTree tree();
    tree.insert(23);
    tree.insert(67);
    tree.insert(12);
    tree.insert(34);
    tree.insert(12);
    tree.insert(6);
    tree.insert(22);
    tree.display();
    return 0;
}