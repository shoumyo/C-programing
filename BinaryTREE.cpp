#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    public:

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void Preorder(struct Node* root){

    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root){

    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(struct Node* root){

    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* PREIN(int preorder[],int inorder[],int start,int end){

    static int idx=start;
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }

    if(start>end){
        return NULL;
    }
    int pos=search(inorder,start,end,curr);

    node->left=PREIN(preorder,inorder,start,pos-1);
    node->right=PREIN(preorder,inorder,pos+1,end);

    return node;
}

void InorderPrint(Node* root){

    if(root=NULL){
        return;
    }
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

int main(){

    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Node* root=PREIN(preorder,inorder,0,4);
    Inorder(root);

    return 0;
}