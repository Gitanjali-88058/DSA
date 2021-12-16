#include <iostream>
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


/*node*  mergeRecursive(node* &head1,node* &head2){
   
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    node* result;
    if(head1->data<head2->data){
        result=head1->data;
        result->next=mergeRecursive(head1->next,head2);
        
    }
    else{
        result=head2->data;
        result->next=mergeRecursive(head1,head2->next);

    }

    return result;
    
}*/
node* merge(node* head1,node* head2){
     node* p1=head1;
     node* p2=head2;
     node* dummyNode=new node(-1);
     node* p3=dummyNode;

      while(p1!=NULL && p2!=NULL){
           if(p1->data<p2->data){
               p3->next=p1;
               p1=p1->next;
           }
           else{
               p3->next=p2;
               p2=p2->next;

           }
           p3=p3->next;
      }
      while(p1!=NULL){
          p3->next=p1;
          p1=p1->next;
          p3=p3->next;
      }
      while(p2!=NULL){
          p3->next=p2;
          p2=p2->next;
          p3=p3->next;
      }
      return dummyNode->next;

}
void display(node* head){        //Displays the list
    node* temp=head;
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head1=NULL;
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,8);
    insertAtTail(head1,10);
    display(head1);

    node* head2=NULL;

    insertAtTail(head2,0);
    insertAtTail(head2,1);
    insertAtTail(head2,5);
    insertAtTail(head2,7);
    insertAtTail(head2,9);
    
    
    display(head2);
    node* newHead1=merge(head1,head2);
    display(newHead1);
   
    /*node* newHead2=mergeRecursive(head1,head2);
    display(newHead2);*/

    

    return 0;
}