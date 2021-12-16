#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> st1;
    stack<int> st2;

    public:
     void push(int x){
        if(st1.empty() and st2.empty()){
            st1.push(x);
            return;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
           
        }

    }
    void pop(){
       if(st1.empty()){
           cout<<"Queue is empty\n";
           return;
       }
       st1.pop();
    }
    int getfront(){
        return st1.top();
    }
    bool isempty(){
        if(st1.empty() and st2.empty())
            return true;
        return false;    
    }



void display(){
    stack<int> temp=st1;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
        
    }
    cout<<endl;
}

};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    q.pop();
    q.push(5);
   
    q.pop();
    cout<<q.getfront()<<endl;
    cout<<q.isempty()<<endl;
    q.pop();
    q.pop();
    cout<<q.isempty()<<endl;
    q.pop();
    q.pop();
    cout<<q.isempty()<<endl;
}