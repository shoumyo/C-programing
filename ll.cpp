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
void insert_at_head(node* &head,int val){
    
    node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;

    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;


}
void delete_at_head(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todeletel=head;
    // head=head->next;
    temp->next=head->next;
    head=head->next;
    delete todeletel;

}
void deletion(node* head, int pos){
    if(pos==1){
        delete_at_head(head);
        return;
    }
    node*temp=head;
    int counter=1;
    while (counter!=pos-1)
    {
        temp=temp->next;
        counter++;
    }
    node*todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
    
}
void insert_at_tail(node* &head, int val){
    if(head==NULL){
    insert_at_head(head,val);
    return;
}


    node* n=new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    
}
void display(node* head){
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        
    } while (temp!=head);
    cout<<endl;
    
}

void evenafterodd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;

    while(odd->next !=NULL && even->next !=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenstart;
    if(odd->next !=NULL){
        even->next=NULL;
    }
}


int main(){
    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    display(head);
    insert_at_head(head,6);
    display(head);
    deletion(head,1);
    display(head);

    
    return 0;
}