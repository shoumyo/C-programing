#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class student{
    public :
    string name;
    int age;
    bool gender;

    void printinfo(){
        cout<<"name= ";
        cout<<name<<endl;
        cout<<"Age= "<<age<<endl;
        cout<<"Gender= "<<gender<<endl;
    }

    student(string s){
        name=s;
    }
    student (){
        cout<<"Defalt"<<endl;
    }

    void getname(){
        cout<<name<<endl;
    }
    student(student &a){
        name=a.name;
        age=a.age;
        gender=a.gender;
    }
};

class A{
    public:
    void Afunc(){
        cout<<"FuncA"<<endl;
    }
};

class B:public A{
    public:
    void Bfunc(){
        cout<<"FuncB"<<endl;
    }
};

class C:public B{
    public:
    void Cfunc(){
        cout<<"FuncC"<<endl;
    }
};

//polymorphism

class Apnacollege{
    public:
    void fun(){
        cout<<"I am a function with nno arguments."<<endl;
    }
    void fun(int x){
        cout<<"I am a function with int argument."<<endl;
    }
    void fun(double x){
        cout<<"I am a function with double argument."<<endl;
    }
};

class complex{
    private:
    int real,imag;
    public:
    complex(int r=0,int i=0){
        real=r;
        imag=i;
    }


    complex operator + (complex const &obj){
        complex res;
        res.imag=imag+obj.imag;
        res.real=real+obj.real;
        return res;
    }
    void display(){
        cout<<real<<" +i"<<imag<<endl;
    }
};

class base{
    public:
    virtual void print(){
        cout<<"This is the base class's print function"<<endl;
    }
    virtual void display(){
        cout<<"This is the base class's display function"<<endl;
    }
};

class derived:public base{
    public:
    void print(){
        cout<<"this is deriverd class's print function"<<endl;
    }
    void display(){
        cout<<"This is derived class's display function"<<endl;
    }
};

int main(){


    return 0;
}