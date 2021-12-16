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
bool search(node* head, int key){     // Search the element
    node* temp=head; 
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }temp=temp->next;
    }
    return false;
}
void delAtHead(node* &head){      //Delete the element from head
    node*temp=head;
    head=temp->next;
    


}

void deletion(node* &head, int val){        //For deletion
    node* temp=head;
    if(temp->data==val){
        delAtHead(head);
        return;

    }

    if(head==NULL){         //IF list is already empyt
        return;
    }

    if(head->next==NULL){       //If there is only one element present
        delAtHead(head);
    } 
    while(temp->next->data!=val){
        temp=temp->next;
 

    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}


node* reverse(node* &head){         //To reverse
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr ;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
}
int main(){

    node* head=NULL;
    insertAtTail(head,1);
    display(head);
    delAtHead(head);
    display(head);
 
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    

    insertAtHead(head,0);
    insertAtHead(head,-1);
    insertAtHead(head,-2);
    display(head);
    cout<<search(head,-1)<<endl;
    cout<<search(head,6)<<endl;
    
    deletion(head,3);
    display(head);
    deletion(head,5);
    display(head);
    
    delAtHead(head);
    display(head);


       node* newhead= reverse(&head)
    display(newhead);

}

