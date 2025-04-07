#include<iostream>
#include<stack>
using namespace std;

//APPROACH 1

class queue{
    stack<int>s1;
    stack<int>s2;

    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() and s2.empty()){
            cout<<"It is empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int toval=s2.top();
            s2.pop();

            return toval;
        }
    }

    bool empty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};

//APPROACH 2

class que{
    stack<int>s3;

    public:

    void push(int x){
        s3.push(x);
    }

    int pop(){
        if(s3.empty()){
            cout<<"It is empty"<<endl;
            return -1;
        }
        int x=s3.top();
        s3.pop();

        if(s3.empty()){
            return x;
        }
        int item=pop();
        s3.push(x);

        return item;
    }

    bool empty(){
        if(s3.empty()){
            return true;
        }
        return false;
    }
};

int main(){

    que q;
    cout<<q.pop()<<endl;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.empty()<<endl;

    return 0;
}