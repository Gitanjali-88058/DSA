#include<iostream>
#include<stack>
using namespace std;

stack<int> GetSum(stack <int> st1,stack <int>  st2){

    stack<int> res;
    int sum=0;
    int rem=0;

    while(!st1.empty() && !st2.empty())
    {
        sum=rem+st1.top()+st2.top();
        res.push(sum%10);
        rem=sum/10;
        st1.pop();
        st2.pop();


    }
    while(!st1.empty()){
        sum=rem+st1.top();
        res.push(sum%10);
        rem=sum/10;
        st1.pop();
    }
    while(!st2.empty()){
        sum=rem+st2.top();
        res.push(sum%10);
        rem=sum/10;
        st2.pop();
    }

    while(rem>0){
        res.push(rem);
        rem/=10;
    }
    stack <int> result;
    while(!res.empty()){
        result.push(res.top());
        
        res.pop();
    }
     
    return result;
}
void display(stack<int> & res){
    int N=res.size();
    string s="";
    while(!res.empty()){
        s=to_string(res.top())+s;
        res.pop();
    }
    cout<<s<<endl;
}
stack<int> getStack(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]-'0');
    }
    return st;
}
int main(){
stack <int> st1;
stack <int> st2;
string s1="23456";
string s2="23456";
/*for(int i=0;i<s1.length();i++){
    st1.push(s1[i]-'0');
}

for(int i=0;i<s2.length();i++){
    st2.push(s2[i]-'0');
}*/
st1=getStack(s1);
st2=getStack(s2);

//st1.push("592");
//st1.push(20);
//st1.push(9);
//st1.push(2);
//st2.push(70);
//st2.push(8);

//st2.push("786");
//st2.push(6);
stack <int> result=GetSum(st1,st2);

display(result);
return 0;
}