#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack <char> st;
    int n=s.size();
    bool ans=true;
    if(s[0]==')' || s[0]=='}' || s[0]==']')
        {
            return false;
           
        }
     
    for(int i=0;i<n;i++){
        
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
            st.pop();
            }
            else{
                ans= false;
                break;
            }

        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
            st.pop();
            }
            else{
                ans= false;
                break;
            }
            
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
            st.pop();
            }
            else{
                ans= false;
                break;
            }

            
        }
        

    }
    
    if(!st.empty()){
        ans=false;
    }
    return ans;
    
}

int main(){
    string s="[()]{}{[(aabc)()]()}";
    if(isValid(s)==true){
        cout<<"Balanced."<<endl;
    }
    else {
        cout<<"UnBalanced."<<endl;
    }

}