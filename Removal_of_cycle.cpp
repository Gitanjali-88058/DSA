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


void makeCycle(node* &head,int pos)    //to make the cycle
{
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;

}

bool detectCycle(node* &head){   //to detect the cycle
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}


void remove(node* &head){   //To remove the cycle.

    node* slow=head;
    node* fast=head;


    do{
        slow=slow->next;
        fast=fast->next->next;
    
    }while(slow!=fast);

    fast=head;
    
    while(fast->next!=slow->next){

      slow=slow->next;
      fast=fast->next;


    }
    slow->next=NULL;


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


    makeCycle(head,3);
    //display(head);
   cout<<detectCycle(head)<<endl;
   remove(head);
   cout<<detectCycle(head)<<endl;
   

}