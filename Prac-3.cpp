/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at position in the singly linked list
(iii)Remove an element from the beginning of the singly linked list
(iv) Remove an element from position in the singly linked list.
(v) Search for an element x in the singly linked list and return its pointer
(vi) Concatenate two singly linked lists*/

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
 
 void insertAtHead(node* &head, int val){      //(i)
     node* n=new node(val);
     node* temp=head;
     n->next=head;
     head=n;
 }


 void insertAtTail(node* &head,int val){   //(ii)
     node* n=new node(val);
     node* temp=head;
     if(head==NULL){
         head=n;
         return;
     }
     while(temp->next!=NULL){
         temp=temp->next;

     }
     temp->next=n;

 }
 
 void delAtHead(node* &head){   //(iii)
       
     node* temp=head;
    
     head=temp->next;
     return;


 }

 void deletion(node* &head,int pos){    //(iv)
      
      node* temp=head;
      int count=1;
      if(pos==1){
          delAtHead(head);
          return;
      }
      if(head==NULL){
          return ;
      }
    
      while(count!=pos-1){
          temp=temp->next;
          count++;

      }
      node* todelete=temp->next;
      temp->next=temp->next->next;
      delete todelete;



 }

 bool search(node* &head, int key){         //(v)
       
     node* temp=head;

     while(temp!=NULL){
         
        if(temp->data==key){
            cout<<(temp->data)<<endl;
             return true;  
         }
         temp=temp->next;
         
         
     }
     return false;


 }

 node* merge(node* &head1, node* &head2){   //(vi)
     node* temp1=head1;
     node* temp2=head2;

     while(temp1->next!=NULL){
         temp1=temp1->next;
     }
     while(temp1->next==NULL && temp2->next!=NULL){
     temp1->next=temp2;
     temp2=temp2->next;
     }
     
 }

 void display(node* head){
    
     node* temp=head;
     
     while(temp!=NULL){
         cout<<temp->data<<"->";
         temp=temp->next;
     }
     cout<<"NULL"<<endl;

 }
 
void menu()
{
    cout << "Press 1 Insert an element at the beginning \n";
    cout << "Press 2 Insert an element at the end \n";
    cout << "Press 3 Remove an element from the beginning\n";
    cout << "Press 4 Remove an element from the given position\n";
    cout << "Press 5 Search an element\n";
    cout << "Press 6 Concatenation of two linked list\n";
    cout << "Press 7 To exit\n";
}

void execute(int choice){
    
    switch(choice){
        case 1:{
            cout<<"----------------------------------"<<endl;
            cout<<"Insert an element at the beginning"<<endl;
          node* head=NULL;
          for(int i=0;i>=-4;i--){
              insertAtHead(head,i);
          }
          display(head);
          
        
          break;
        }
        case 2:{
            cout<<"------------------------------"<<endl;
            cout<<"Insert an element at the end"<<endl;
            node* head=NULL;
            for(int i=1;i<=4;i++){
                insertAtTail(head,i);
            }
            display(head);
            
         break;
        }
        case 3:{
            node* head=NULL;
          for(int i=0;i>=-4;i--){
              insertAtHead(head,i);
          }
          for(int i=1;i<=4;i++){
                insertAtTail(head,i);
          }
            cout<<"------------------------------"<<endl;
            display(head);
            cout<<endl;
            cout<<"Removing an element from the beginning"<<endl;
            delAtHead(head);
            display(head);
            
            break;

        }
        case 4:{
            node* head=NULL;
          for(int i=0;i>=-4;i--){
              insertAtHead(head,i);
          }
          for(int i=1;i<=4;i++){
                insertAtTail(head,i);
          }
            cout<<"---------------------------------"<<endl;
            display(head);
            cout<<endl;
            int pos;
            cout<<"Enter the position of element need to remove: "<<endl;
            cin>>pos;
            cout<<endl;
            cout<<"Removing an element from the position given."<<endl;
            deletion(head,pos);
            display(head);
            
            break;


        }
        case 5:{
            node* head=NULL;
          for(int i=0;i>=-4;i--){
              insertAtHead(head,i);
          }
          for(int i=1;i<=4;i++){
                insertAtTail(head,i);
          }
          display(head);
            cout<<"--------------------------------"<<endl;
            cout<<"Searching a given element"<<endl;
            
            int key;
            cout<<"Enter the element to find: ";
            cin>>key;
            cout<<endl;
            cout<<search(head,key)<<endl;
           
            break;

        }
        case 6:{
            cout<<"--------------------------------"<<endl;
            cout<<"Concatenating the two linked list"<<endl;
            node* head1=NULL;
            node* head2=NULL;
            for(int i=1;i<=4;i++){
                insertAtTail(head1,i);
            }
            display(head1);
            for(int i=5;i<9;i++){
                insertAtTail(head2,i);
            }
            display(head2);
            
            merge(head1,head2);
            cout<<"Merged list: ";
            display(head1);
      
            break;

        }
        default:
            cout<<"\n\n-------------------------------"<<endl;
            break;
        
    }

} 

int main(){
    
    menu();
    int choice=0;
    do{
    
    cout<<"Enter from 1 to 7: ";
    cin>>choice;
    
    execute(choice);
    }while(choice!=7);

    cout<<"\n\n-------------------------------"<<endl;

    return 0;
   
}