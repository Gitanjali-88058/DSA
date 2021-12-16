#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s){

    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
       
        if(s[i]>='0' && s[i]<='9' ){
            st.push(s[i]-'0');
        }
        else{
            int ope1=st.top();
            st.pop();
            int ope2=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(ope1+ope2);
                    break;
                case '-':
                    st.push(ope1-ope2);
                    break;
                case '*':
                    st.push(ope1*ope2);
                    break;  
                case '/':
                    st.push(ope1/ope2);
                    break;
                case '^':
                    st.push(pow(ope1,ope2));
                    break;  
                default:
                    break;    
            }
        }
    }
    return st.top();
}
int postfixEvaluation(string s){
    
    stack<int> st;

    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9' ){
            st.push(s[i]-'0');
        }
        else{
            int ope2=st.top();
            st.pop();
            int ope1=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(ope1+ope2);
                    break;
                case '-':
                    st.push(ope1-ope2);
                    break;
                case '*':
                    st.push(ope1*ope2);
                    break;  
                case '/':
                    st.push(ope1/ope2);
                    break;
                case '^':
                    st.push(pow(ope1,ope2));
                    break;  
                  
            }
        }
    }
    return st.top();
}




int main(){
    //string s="-+7*45+20";
    
   
    cout<<"Prefix Evaluation: "<<prefixEvaluation("-+7*45+20")<<endl;
   // cout<<"Hello World!"<<endl;
    cout<<"Postfix Evaluation: ";
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}