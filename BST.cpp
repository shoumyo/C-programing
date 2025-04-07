#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};


Node *insertBST(Node *root,int val){

    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

Node* searchInBST(Node *root,int k){

    if(root==NULL){
        return NULL;
    }

    if(root->data==k){
        return root;
    }
    if(root->data<k){
        return searchInBST(root->left,k);
    }
    return searchInBST(root->right,k);
}

Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left !=NULL){
        curr=curr->left;
    }
    return curr;
}

Node *deleteInBST(Node* root,int key){
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if(root->data<key){
        root->right=deleteInBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}

Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    Node* root=NULL;

    if(*preorderIdx>=n){
        return NULL;
    }

    if(key>min && key<max){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;

        if(*preorderIdx<n && preorder[*preorderIdx]<key){
            root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n && preorder[*preorderIdx]>key){
            root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}

bool isBST(Node *root,Node* min=NULL, Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min !=NULL && root->data<=min->data){
        return false;
    }
    if(max !=NULL && root->data>=max->data){
        return false;
    }

    bool lvalid=isBST(root->left,min,root);
    bool rvalid=isBST(root->right,root,max);

    return lvalid and rvalid;
}

Node *sortedArrayToBST(int arr[],int start,int end){

    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node*root=new Node(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);

    return root;
}

void inorderPrint(Node *root){

    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" "; 
    inorderPrint(root->right);
}

void preorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int catalan(int n){
    
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

vector<Node*>possibleBST(int start,int end){

    vector<Node*>tree;

    if(start>end){
        tree.push_back(NULL);
        return tree;
    }
    for(int i=start;i<=end;i++){
        vector<Node*>ltree=possibleBST(start,i-1);
        vector<Node*>rtree=possibleBST(i+1,end);

        for(int j=0;j<ltree.size();j++){
            Node* l=ltree[j];

            for(int k=0;k<rtree.size();k++){
                Node*r=rtree[k];

                Node* node=new Node(i);
                node->left=l;
                node->right=r;
                tree.push_back(node);
            }
        }
    }
    return tree;
}

void zicZac(Node* root){
    if(root==NULL){
        return;
    }

    stack<Node*>currlevel;
    stack<Node*>nextlevel;

    bool leftToRight=true;
    currlevel.push(root);

    while(!currlevel.empty()){
        Node*temp=currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left){
                    nextlevel.push(temp->left);
                }
                if(temp->right){
                    nextlevel.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextlevel.push(temp->right);
                }
                if(temp->left){
                    nextlevel.push(temp->left);
                }
            }
        }
        if(currlevel.empty()){
            leftToRight=!leftToRight;
            swap(currlevel,nextlevel);
        }
    }
}

bool isIdentical(Node* root1,Node* root2){

    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
}

Info largerstBST(Node*root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    Info leftInfo=largerstBST(root->left);
    Info rightInfo=largerstBST(root->right);

    Info curr;
    curr.size=(1+leftInfo.size+rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
        curr.min=min(root->data,min(rightInfo.min,leftInfo.min));
        curr.max=max(root->data,max(leftInfo.max,rightInfo.max));

        curr.ans=curr.size;
        curr.isBST=true;

        return curr;
    }
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}

void calcPointer(Node* root,Node** first,Node** mid,Node** last,Node** prev){

    if(root==NULL){
        return;
    }

    calcPointer(root->left,first,mid,last,prev);
    if(*prev && root->data<(*prev)->data){
        if(! *first){
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calcPointer(root->right,first,mid,last,prev);
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void restoreBST(Node* root){
    Node* first=NULL;
    Node* mid=NULL;
    Node*last=NULL;
    Node* prev=NULL;

    calcPointer(root,&first,&mid,&last,&prev);
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    else if(first && mid){
        swap(&(first->data),&(last->data));
    }
}

int main(){

    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(9);
    root->right->right=new Node(8);

    restoreBST(root);
    inorderPrint(root);
    preorderPrint(root);

    return 0;
}