#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int a[N],tree[4*N];

void build(int node,int st,int en){

    if(st==en){
        tree[node]=a[st];
        return ;
    }

    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node,mid+1,en);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return 0;
    }
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);

    for(int i=1;i<15;i++){
        cout<<tree[i]<<endl;
    }

    return 0;

}