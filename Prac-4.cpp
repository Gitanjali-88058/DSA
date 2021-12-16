/*4. Write a program to implement doubly linked list which supports the following operations:
(i) Insert an element x at the beginning of the doubly linked list
(ii)Insert an element x at position in the doubly linked list
(iii)Insert an element x at the end of the doubly linked list
(iv) Remove an element from the beginning of the doubly linked list
(v) Remove an element from position in the doubly linked list.
(vi) Remove an element from the end of the doubly linked list
(vii) Search for an element x in the doubly linked list and return its pointer
(viii) Concatenate two doubly linked lists */
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
  

    head=n;

}

void insertAtTail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;

    }
    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;

}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;

    }
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    if(temp->next!=NULL){
      temp->next->prev=temp->prev;  
    }
    temp->prev->next=temp->next;
    

      delete temp;


}

void display(node* head){
   node* temp=head;
   cout<<"NULL ";
   while(temp!=NULL){
       cout<<temp->data<<" ";
       
       temp=temp->next;
   }
   cout<<"NULL"<<endl;

}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    insertAtHead(head,0);
    insertAtHead(head,-1);
    insertAtHead(head,-2);
    insertAtHead(head,-3);
    insertAtHead(head,-4);

    display(head);

    deletion(head,4);
    display(head);
    deletion(head,1);
    display(head);
    deletion(head,8);
    display(head);
    return 0;
}