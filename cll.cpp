#include<iostream>
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

void insert_At_Head(node* &head,int val){
    node* n=new node(val);
    
    if(head==NULL){
        n->next=head;
        head=n;
        return;
    }
    node* temp=head;    
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insert_At_Tail(node* &head,int val){
    
    node* n=new node(val);
    node* temp=head;

    if(head==NULL){
        insert_At_Head(head,val);
        return;
    }

    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void delete_At_Head(node* &head){
    node*temp=head;
    //store the value in a temporary file
    while(temp->next !=head){
        temp=temp->next;
        //reach to the end
    }
    node* todelete=temp->next;
    //store the head for delete
    temp->next=head->next;
    head=head->next;
    //fixing the linked list

    delete todelete;
    //deleted the data
}

void deletion(node* &head,int pos){
    //which position of the list you want to delete
    //use of & means we will change the data of the head list

    if(pos==1){ 
         //we have stared position from 1,that's why position 1 means head
        delete_At_Head(head);
        return;
    }
    node *temp=head;
    //a temporary list to store the data of head
    int count=1;
    //starts from head

    while(count !=pos){
        temp=temp->next;
        count++;
        //from this loop we will reach one positon bach of the needed position which we have to delete
    }
    node* todelete=temp->next;
    //we will store that data to todelete node sothat we can delete it
    //than we will fixed the circular linked list and take out the data from the list
    temp->next=temp->next->next;
    //than we will delete the data
    delete todelete;
}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp !=head);//print upto temp node becomes the head
    cout<<endl;

}



int main(){

    node* head=NULL;
    insert_At_Tail(head,1);
    insert_At_Tail(head,2);
    insert_At_Tail(head,3);
    insert_At_Tail(head,4);
    insert_At_Tail(head,5);
    display(head);
    insert_At_Head(head,0);
    display(head);
    deletion(head,1);
    display(head);

    return 0;
}