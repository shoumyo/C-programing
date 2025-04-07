#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string s){    //reverse a sentence
    stack<string>st;
    //new stack created in a string format

    for(int i=0;i<s.size();i++){
        string word=" ";
        //new string to store a word

        while(s[i] !=' ' && i<s.size()){
            word+=s[i];
            //adding thw word to the word function by a single word

            i++;
        }
        st.push(word);
        //when the word is done then pushing it to the stack
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
        //printing the stack from the top until the stack is empty to revese the sentence
        //using pop to print every word from the stack because we can only use stack from the top
    }
    cout<<endl;
}

void insertAtBottom(stack<int> &st,int ele){

    //a function which is call by reference to store a value in the bottom in the given stack
    
    if(st.empty()){
        st.push(ele);
        //base case
        return;
    }
    int topele=st.top();
    //storing the top

    st.pop();

     insertAtBottom(st,ele);
    //reaching at the bottom of the stack using recursive function

    st.push(topele);
    //store the top value at the bottom 

   
}

void reverseStack(stack<int>&st){  //reverse a stack
    //using "&" because st is going to change in the function

    if(st.empty()){
        return;
        //base case
    }

    int ele=st.top();
    st.pop();

    reverseStack(st);
    //using recursive function to reach at the bottom of the st stack

     insertAtBottom(st,ele);
    //using this function to store the top (which is saved at ele) at the bottom 

    
}

int main(){

    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    //can't print the actual stack because it will be empty so the function is useless


    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    

    

    return 0;
}