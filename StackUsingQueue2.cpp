#include<bits/stdc++.h>
//#include<queue>
using namespace std;
class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
    public: 
    Stack(){
        N=0;
    }

    void push(int x){
        q1.push(x);
        N++;
    }
    void pop(){
        if(q1.empty()){
            return ;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue <int> temp=q1;
        q1=q2;
        q2=temp;
 

    }
    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int topele=q1.front();
        q2.push(topele);
        q1.pop();
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
        return topele;

    }
    int size(){
        return N;
    }

    /*void display(){
        queue<int> temp;
        temp=q1;
        while(!temp.empty()){
            q2.push(temp.front());
            temp.pop();
        }
    


        
        while(!q2.empty()){
            cout<<q2.back()<<" ";
            q2.pop();
        }
        cout<<endl;
    }*/
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
}