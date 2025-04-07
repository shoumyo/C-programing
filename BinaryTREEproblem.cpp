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

void PrintLevelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node=q.front();
        q.pop();

        if(node !=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumAtK(Node* root,int key){

    if(root==NULL){
        return -1;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    int level=0;
    int sum=0;

    while(!q.empty()){
        Node* node=q.front();
        q.pop();

        if(node !=NULL){
            if(level==key){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int countNodes(Node* root){

    if(root==NULL){
        return 0;
    }

    return countNodes(root->left)+countNodes(root->right)+1;
}

int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int HeightofTree(Node* root){

    if(root==NULL){
        return 0;
    }

    int lheight=HeightofTree(root->left);
    int rHeight=HeightofTree(root->right);

    return max(lheight,rHeight)+1;
}

int diameterofTREE1(Node* root){

    if(root==NULL){
        return 0;
    }
    int lheight=HeightofTree(root->left);
    int rheight=HeightofTree(root->right);
    int currdiameter=lheight+rheight+1;

    int ldiameter=diameterofTREE1(root->left);
    int rdiameter=diameterofTREE1(root->right);

    return max(currdiameter,max(ldiameter,rdiameter));
}

int diameterofTREE2(Node* root,int* height){
    //more optimized

    if(root==NULL){
        return 0;
        *height=0;
    }
    int lh=0,rh=0;
    int LD=diameterofTREE2(root->left,&lh);
    int RD=diameterofTREE2(root->right,&rh);

    int currd=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currd,max(LD,RD));
}

void sumREPLACE(Node* root){

    if(root==NULL){
        return;
    }

    sumREPLACE(root->left);
    sumREPLACE(root->right);

    if(root->left !=NULL){
        root->data+=root->left->data;
    }

    if(root->right !=NULL){
        root->data+=root->right->data;
    }
}

void InorderPrint(Node* root){

    if(root==NULL){
        return;
    }
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

bool isBALANCED1(Node* root){

    if(root==NULL){
        return true;
    }

    if(isBALANCED1(root->left)==false){
        return false;
    }

    if(isBALANCED1(root->right)==false){
        return false;
    }

    int lh=HeightofTree(root->left);
    int rh=HeightofTree(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}

bool isBALANCED2(Node* root,int* height){
    //More optimized method

    int lh=0,rh=0;

    if(root==NULL){
        return true;
    }

    if(isBALANCED2(root->left,&lh)==false){
        return false;
    }

    if(isBALANCED2(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh);

    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}

void rightVIEW(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            if(curr->right !=NULL){
                q.push(curr->right);
            }
        }
    } 
}

Node* LCA(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* l=LCA(root->left,n1,n2);
    Node* r=LCA(root->right,n1,n2);

    if(l !=NULL && r !=NULL){
        return root;
    }

    if(l==NULL && r==NULL){
        return NULL;
    }
    if(l !=NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int findDISTANCE(Node* root,int k,int dist){
    if(root==NULL){
        return -1;
    }

    if(root->data==k){
        return dist;
    }

    int l=findDISTANCE(root->left,k,dist+1);
    if(l !=-1){
        return l;
    }
    return findDISTANCE(root->right,k,dist+1);
}

int distanceBETWEENnodes(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int d1=findDISTANCE(lca,n1,0);
    int d2=findDISTANCE(lca,n2,0);

    return d1+d2;
}

void leftVIEW(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*>q1;
    q1.push(root);

    while(!q1.empty()){
        int m=q1.size();

        for(int i=1;i<=m;i++){
            Node* temp=q1.front();
            q1.pop();

            if(i==1){
                cout<<temp->data<<" ";
            }
            if(temp->left !=NULL){
                q1.push(temp->left);
            }
            if(temp->right !=NULL){
                q1.push(temp->right);
            }
        }
    }
}

void flatter(Node* root){
    //flatter into preorder

    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }

    if(root->left !=NULL){
        flatter(root->left);

        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* t=root->right;
        while(t->right !=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatter(root->right);
}

void printSUBTREEnodes(Node* root,int k){
    if(root== NULL || k<0){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
    }

    printSUBTREEnodes(root->left,k-1);
    printSUBTREEnodes(root->right,k-1);
}

int printNODESatK(Node* root,Node*target,int k){

    if(root==NULL){
        return -1;
    }

    if(root==target){
        printSUBTREEnodes(root,k);
        return 0;
    }

    int dl=printNODESatK(root->left,target,k);
    if(dl !=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSUBTREEnodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr=printNODESatK(root->right,target,k);
    if(dr != -1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSUBTREEnodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

bool getPATH(Node* root,int key,vector<int>&path){

    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPATH(root->left,key,path) || getPATH(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int lowestCOMMONancestor1(Node* root,int n1,int n2){

    vector<int>path1,path2;

    if(!getPATH(root,n1,path1) || !getPATH(root,n2,path2)){
    return -1;
    }

    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}

Node* low(Node* root,int n1,int n2){
    //optimized method

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 ||  root->data ==n2){
        return root;
    }
    Node* llca=low(root->left,n1,n2);
    Node* rlca=low(root->right,n1,n2);

    if(llca && rlca){
        return root;
    }
    if(llca !=NULL){
        return llca;
    }
    return rlca;
}

int maxpathsumutil(Node*root,int ans){
    if(root==NULL){
        return 0;
    }
    int l=maxpathsumutil(root->left,ans);
    int r=maxpathsumutil(root->right,ans);

    int nodemax=max(max(root->data,root->data+l+r),max(root->data+l,root->data+r));
    ans=max(ans,nodemax);

    int single=max(root->data,max(root->data+l,root->data+r));

    return single;
}

int mxaPATHsum(Node* root){
    int ans=INT_MIN;

    maxpathsumutil(root,ans);
    return ans;
}

void inorderPRINT(Node* root){

    if(root==NULL){
        return;
    }

    inorderPRINT(root->left);
    cout<<root->data<<" ";
    inorderPRINT(root->right);
}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(6);
    root->left->left->right=new Node(7);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    root->right->left=new Node(10);
    root->right->left->left=new Node(12);
    root->right->left->right=new Node(13);
    root->right->right=new Node(11);
    root->right->right->left=new Node(14);
    root->right->right->right=new Node(15);

    cout<<mxaPATHsum(root);
    return 0;
}