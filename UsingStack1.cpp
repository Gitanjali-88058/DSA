#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int> s1;
    public:
    void push(int x){
        s1.push(x);

    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty."<<endl;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return(item);
    }
    bool empty(){
        if(s1.empty()){
            return true;
    }
    return false;
    }

    void display(){
        while(!s1.empty()){
            cout<<s1.top()<<" ";
            s1.pop();
        }
    }

};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
    
    
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;

}
