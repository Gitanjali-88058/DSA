#include"bits/stdc++.h"
using namespace std;
const int size=20;
int count_leaf=0;
int count_nonleaf=0;

class node{
    public:
          int info;
          node* left;
          node* right;

}*root=NULL;
class bst{
    node *p,*q,*p1;
    public:
    void insert();
    void recursive_inorder(node*);
    void recursive_preorder(node*);
    
}