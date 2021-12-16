#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){   //Adding element at head
    node* n=new node(val);
    n->next=head;
    head=n;

    
}
void insertAtTail(node* &head,int val){    //Adding element at tail
    node* n=new node(val);
    
    if(head==NULL){               //If List is already empty
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
}
void display(node* head){        //Displays the list
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int length(node* &head){
    int l;
    node* temp=head;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* k_append(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int count=1;
    int l=length(head);
    
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;

        }
        if(count==l-k+1){
            newHead=tail;
        }
        
        tail=tail->next;
        count++;
    }

    tail->next=head;
    newTail->next=NULL; 

    return newHead;


}
int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);

    display(head);
    node* newHead=k_append(head,3);
    display(newHead);


  

}
