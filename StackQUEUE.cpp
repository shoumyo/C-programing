#include<iostream>
#include<queue>
using namespace std;

//We are making stack using queue

//APPROACH 1

class stack{

    queue<int>q1;
    queue<int>q2;
    int N;

    public:

    stack(){
        N=0;
    }

    void push(int val){
        q2.push(val);
        N++;

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }

    int size(){
        return N;
    }
};

//APPROACH 2

class Stack{

    int N;
    queue<int>q3;
    queue<int>q4;

    public:

    Stack(){
        N=0;
    }

    void pop(){
        if(q3.empty()){
            return;
        }

        while(q3.size() != 1){
            q4.push(q3.front());
            q3.pop();
        }
        q3.pop();
        N--;

        queue<int>temp=q3;
        q3=q4;
        q4=temp;
    }

    void push(int x){
        q3.push(x);
        N++;

    }

    int top(){
        if(q3.empty()){
            return -1;
        }

        while(q3.size() != 1){
            q4.push(q3.front());
            q3.pop();
        }

        int ans=q3.front();
        q4.push(ans);

        queue<int>temp=q3;
        q3=q4;
        q4=temp;

        return ans;
    }

    int size(){
        return N;
    }
};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.size()<<endl;


    return 0;
}