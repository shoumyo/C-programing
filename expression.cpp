#include<iostream>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

int prefixEvakuation(string s){
    //solving a prefix function

    stack<int>st;

    for(int i=s.size()-1;i>=0;i--){
        //starts from the last
        //sttring starts from 0,thats why "n-1"
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
            //if the string has number saved into the stack it's value
        }
        else{
            //if there is a sign catch two numbers from the stack
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i]){

                //those two numbers from stack and the sign from the string
                //making the two numbers into one numbers using the sign and puting back to the stack

                case '+':
                st.push(op1+op2);
                break;

                case '-':
                st.push(op1-op2);
                break;

                case '*':
                st.push(op1*op2);
                break;

                case '/':
                st.push(op1/op2);
                break;

                case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
    //because finally the top value of the stack will be the ans
}

int postfixExpression(string s){
    //solving a postfix expression

    stack<int>stt;
    //making a stack of integer value named stt

    for(int i=0;i<s.size();i++){
        //a loop starting from the begining of the string to last

        if(s[i]>='0' && s[i]<='9'){
            //if threre is a number in the string save the value into the stack
            stt.push(s[i]-'0');
        }
        else{
            //if there is a sign in a string taking out first two value from stack and save them

            int op2=stt.top();
            stt.pop();
            int op1=stt.top();
            stt.pop();
            //sving the sceond number to the first one because we are counting from the left side
            //in postfix the sign is after the number and in the stack we acess the sceond number first

            switch(s[i]){
                //making the two numbers into one number using the sign and putting back into the stack

                case '+':
                stt.push(op1+op2);
                break;

                case '-':
                stt.push(op1-op2);
                break;

                case '*':
                stt.push(op1*op2);
                break;

                case '/':
                stt.push(op1/op2);
                break;

                case '^':
                stt.push(pow(op1,op2));
                break;
            }
        }
    }
    return stt.top();
}

int prec(char c){
    //a precidence to the signs
    //the more returns the more solve in the first

    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    //convert infix into profix

    stack<char>st1;
    //the stack is a character type because we are going to store character

    string res;
    //a string to store the result

    for(int i=0;i<s.size();i++){
        //from starting to end of the string

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
            //if the string has a character store that int the res string
        }

        else if(s[i]=='('){
            st1.push(s[i]);
            //if there is a starting bracket store it in the stack
        }

        else if(s[i]==')'){
            while(!st1.empty() && st1.top() !='('){
                res+=st1.top();
                st1.pop();
            }
            //while there is a close bracket sign in the string pop out all the stack character utill the starting bracket come

            if(st1.empty()){
                st1.pop();
                //if it is empty
            }
        }

        else{
                while(!st1.empty() && prec(st1.top())>prec(s[i])){
                    res+=st1.top();
                    st1.pop();
                }
                st1.push(s[i]);

                //if it is not empty and the precedence of the top of the stack is bigger than remaining string
                //do pop out until the string precedence is more than top is bigger and store it in the res
                //then store the string sign into the stack
                //if the staqck becomes empty store the string sign into the stack
        }
    }
    while(!st1.empty()){

        if(st1.top()=='('){
            st1.pop();
            //to prevent the startin bracket into the result
        }
        else{
            res+=st1.top();
            st1.pop();
        }
    }
    //when the loop ends pop out veery character from the stack and store it into the res string serially 
    //than return the result string because it's the ans

    return res;
}

string infixToPrefix(string s){
    //convert infix to profix
    //have to do in 4 steps

    reverse(s.begin(),s.end());
    //first step is to reverse the whole string

    for(int i=0;i<s.size();i++){
        if(s[i]=='('  || s[i]==')'){
            if(s[i]=='('){
                s[i]=')';
            }
            else{
                s[i]='(';
            }
        }
        //sceond step
        //changing the brackets
        //turning the brackets into their opposite
    }

    string result=infixToPostfix(s);
    //third step
    //turing the infix string into postfix string and storing the result

    reverse(result.begin(),result.end());
    //forth step
    //reversing the result again to get the actual result

    return result;
}

//balanced parenthesis

bool isValid(string s){
    int n=s.size();
    stack<char>st2;
    for(int i=0;i<n;i++){
        if(s[i]='(' || s[i]=='[' || s[i]=='{'){
            st2.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st2.empty() && st2.top()=='('){
                st2.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]=='}'){
            if(!st2.empty() && st2.top()=='{'){
                st2.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(!st2.empty() && st2.top()=='['){
                st2.pop();
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(st2.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string s="[{()}]";
    if(!isValid(s)){
        cout<<"Balanced parenthesis is valid"<<endl;
    }
    else{
        cout<<"Balanced parenthesis is not valid"<<endl;
    }

    return 0;
}