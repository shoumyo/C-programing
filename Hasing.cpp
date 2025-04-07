#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right,*left;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void getVerticalOrder(Node *root,int hids,map<int,vector<int>>&m){

    if(root==NULL){
        return;
    }

    m[hids].push_back(root->data);
    getVerticalOrder(root->left,hids-1,m);
    getVerticalOrder(root->right,hids+1,m);
}

int minimumSumOfK(vector<int>a,int n,int k){

    int s=0;
    int ans=INT_MAX;

    for(int i=0;i<k;i++){
        s+=a[i];
    }

    ans=min(ans,s);

    for(int i=k;i<n;i++){
        s+=a[k];
        s-=a[i-k];
        ans=min(ans,s);

    }
    return ans;
}

int main(){

   int n,k;
   cin>>n>>k;
   vector<int>a(n);

   for(int i=0;i<n;i++){
    cin>>a[i];
   }

   map<int,int>m;

   for(int i=0;i<n;i++){
    int presentsize=m.size();
    if(m[a[i]]==0 && presentsize==k){
        break;
    }
    m[a[i]]++;
   }
   vector<pair<int,int>>ans;

   map<int,int> ::iterator it;
   for(it=m.begin();it !=m.end();it++){
    if(it->second !=0){
        pair<int,int>p;
        p.first=it->second;
        p.second=it->first;
        ans.push_back(p);
    }
   }
   sort(ans.begin(),ans.end(),greater<pair<int,int>>());
   vector<pair<int,int>> ::iterator it1;
   for(it1=ans.begin();it1 !=ans.end();it1++){
    cout<<it1->second<<": "<<it1->first<<endl;
   }


    return 0;
}