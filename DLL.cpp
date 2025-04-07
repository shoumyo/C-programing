#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head !=NULL){
        head->prev=n;
    }
    n=head;
}

void insertAtTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* temp=head;

    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node* head){
    node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletation(node* &head,int pos){

    if(pos==1){
        deleteHead(head);
        return;
    }
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!= pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next !=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp != NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* kappend(node* &head,int k){

    node* newhead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int count=1;

    while(tail->next !=NULL){
        if(count==l-k){
            newtail=tail;
        }
        if(count=l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;

    return newhead;
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next !=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1 !=NULL && ptr2 !=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1 !=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    if(p1->data==p2->data){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    while(p1 !=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2 !=NULL){
        p2->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode;
    
}

node* mergeRecursive(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
    return head1;
    }

    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}




int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);

    display(head);

    return 0;
}