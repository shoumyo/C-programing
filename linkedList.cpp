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

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node*n=new node(val);
    n->next=head;
    head =n;
}

void display(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node*temp=head;
    while(temp !=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletation(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead;
        return;
    }
    node*temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
 
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr !=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node*reverseK(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr != NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(nextptr != NULL){
        head->next=reverseK(nextptr,k);
    }
    return prevptr;
}

bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startnode;

    int count=1;

    while(temp->next != NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(fast !=slow);

    fast=head;
    while(slow->next !=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}


int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,0);
    insertAtTail(head,4);
    insertAtHead(head,5);
    insertAtTail(head,6);

    display(head);

    makeCycle(head,3);
    removeCycle(head);
    display(head);

    return 0;
}