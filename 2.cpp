#include "bits\stdc++.h"
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
        return-1;

    }

}
Node* builtTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    
    int curr=preorder[idx];
    idx++;
    Node*  node=new Node(curr);
    if(start==end){
        return node;

    }
    int pos=search(inorder,start, end,curr);
    node->left=builtTree(inorder,preorder,start,pos-1);
    node->right=builtTree(inorder,preorder,pos+1,end);
    return node;
}

void inorderPrint( Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    
    inorderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,5,3};
    int inorder[]={4,2,5,1,3};
    Node* root=builtTree(inorder,preorder,0,4);
    inorderPrint(root);
  
}
/*1 2 4 5 3 
4 2 5 1 3 
4 5 2 3 1 */