#include<iostream>
using namespace std;

#define size 100

class stack{
    int* arr;
    int top;
     
    public:
    stack(){
        top=-1;
        arr=new int[size];
    }
    void push(int);
    void pop();
    int Top();
    bool isEmpty();
    void Size();
    void toClear();
    void display();

};
    void stack :: push(int x){
        if(top==size-1){
            cout<<"Stack overflow."<<endl;

        }
        top++;
        arr[top]=x;
    }

    void stack :: pop(){
        if(top==-1){
            cout<<"No element to pop."<<endl;
            return;
        }
        top--;
    }

    int stack :: Top(){
        if(top==-1){
            cout<<"No element in the stack."<<endl;
            return -1;
        }
        return arr[top];
    }
    bool stack::isEmpty(){
        
            return top==-1;
        
    }
    void stack :: display(){
        if(top==-1){
            cout<<"Stack empty.";

        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl; 
    }
    void stack :: Size(){
        cout<<"Size of the stack: "<<top+1<<endl;

    }
    void stack::toClear(){
        for(int i=top;i>=0;i--){
            pop();
        }

    }


    

void menu()
{
    cout << "Press 1 To Push an element  \n";
    cout << "Press 2 To Pop an element  \n";
    cout << "Press 3 To return the top element \n";
    cout << "Press 4 To find if the stack is empty \n";
    cout << "Press 5 To get the size of the stack\n";
    cout << "Press 6 To clear the stack\n";
    cout << "Press 7 To display the stack\n";
    cout<<  "Press 8 To exit\n";
}


int main(){
    stack st;
    int choice=0;
    
    
    do{
      
      
      menu();
      cout<<"Enter from 1 to 8: ";
      cin>>choice;
      int val;
      switch (choice){
        
        case 1:{
            cout<<"------------------------------------"<<endl;
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            st.push(val);
            break;
            
            
        }

        case 2:{
            cout<<"----------------------------------------"<<endl;
            st.pop();
           
            break;
        }
        case 3:{
            cout<<"----------------------------------------"<<endl;
            cout<<"Element at the top in the stack: "<<st.Top()<<endl;

            break;
        }
        case 4:{
            cout<<st.isEmpty()<<endl;
            break;
        }
        case 5:{
            cout<<"----------------------------------------"<<endl;
            st.Size();
            break;
        }
        case 6:{
            cout<<"----------------------------------------"<<endl;
            st.toClear();
           
            break;
        }
        case 7:{
            cout<<"----------------------------------------"<<endl;
            st.display();
        }

        default:
            cout<<"----------------------------------------"<<endl;
            break;
      }

    }while(choice!=8);

   


    return 0;
}





