//  binary search Tree
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left=nullptr;
    TreeNode*right=nullptr;
    TreeNode(){
        
    }
    TreeNode(int v){
        val=v;
    }
};
void makeTree(TreeNode*&root,int data){
    if(root==nullptr){
        root= new TreeNode(data);
        return ;
    }
    if(data <= root->val){
        makeTree(root->left,data);
    }else if(data > root->val){
        makeTree(root->right,data);
    }
}
void inoreder(TreeNode*root){
    if(!root){
        return ;
    }
    inoreder(root->left);
    cout<<root->val<<" ";
    inoreder(root->right);
}
void reverseInOrder(TreeNode*root){
    if(!root) return ;
    reverseInOrder(root->right);
    cout<<root->val<<" ";
    reverseInOrder(root->left);
}
int main(){
    int data=1;
    TreeNode*root=nullptr;
    while(data != 0){
        cout<<"Enter the data : ";
        cin>>data;
        if(data==0) break;
        makeTree(root,data);
    }
    inoreder(root);
    cout<<endl;
    reverseInOrder(root);
    return 0;
}