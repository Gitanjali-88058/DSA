
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

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    n->next=head;
    if(head!=NULL){
         head->prev=n;
    }
    head=n;
  
}

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    while(temp->next!=NULL){
          temp=temp->next;
     
    }
    temp->next=n;
    n->prev=temp;


}
void deleteAtHead(node* &head){
   node* temp=head;
   node* todelete=head;
   head=head->next;
   head->prev=NULL;

   delete todelete;
}

void deletion(node* &head ,int pos){
   
    node* temp=head;
    if(pos==0){
        deleteAtHead(head);
        return;
    }
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
    cout<<"NULL";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

int main(){
    node* head=NULL;

    insertAtHead(head,0);
    insertAtHead(head,-1);
    insertAtHead(head,-2);
    insertAtHead(head,-3);
    insertAtHead(head,-4);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    deletion(head,0);
    display(head);
    deletion(head,3);
    display(head);
    deleteAtHead(head);
    display(head);
}