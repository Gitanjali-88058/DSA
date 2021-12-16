#include<iostream>
#include<stack>
using namespace std;

int preced(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' && c=='/'){
        return 2;
    }
    else if(c=='+' && c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if('a'<=s[i] && s[i]<='z' || 'A'<=s[i] && s[i]<='Z' || '0'<=s[i] && s[i]<='9'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
                
            }
            if(!st.empty()){
                st.pop();
            }

        }
        else{
            while(!st.empty() && preced(s[i])<preced(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
           
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res; 
    
}

int main(){
    string s="(a-b/c)*(a/k-l)";
    cout<<"Postfix Expressions: "<<infixToPostfix("(A+B)*(C+D)")<<endl;
}