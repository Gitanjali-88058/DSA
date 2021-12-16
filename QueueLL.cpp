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
class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;

    }
    void push(int x){
        node* n=new node(x);
        if(front==NULL){
            front=n;
            back=n;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;

    }
    int peek(){
        if(front==NULL){
            cout<<"No element in queue"<<endl;
            return-1;
        }
        return front->data;

    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    
    void display(node* head){        //Displays the list
        node* temp=head;
        while(temp!=NULL){
             cout<<temp->data<<"->";
             temp=temp->next;
        }
    cout<<"NULL"<<endl;
}
};

int main(){
    
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    //q.display();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    //q.display();
    q.pop();
    //q.display();
    cout<<q.peek()<<endl;
    q.pop();
    //q.display();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.isEmpty()<<endl;
    //q.display();
    



}