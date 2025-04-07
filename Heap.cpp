#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&a,int n,int i){

    int maxIdx=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && a[l]>a[maxIdx]){
        maxIdx=l;
    }
    if(r<n && a[r]>a[maxIdx]){
        maxIdx=r;
    }
    if(maxIdx !=i){
        swap(a[i],a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}

void heapsort(vector<int>&a){
    int n=a.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

priority_queue<int,vector<int>>pqmax;
priority_queue<int,vector<int>,greater<int>>pqmin;

void insert(int x){

    if(pqmin.size()==pqmax.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }

        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        if(pqmax.size()>pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
    }
}

double findMedian(){
    if(pqmax.size()==pqmin.size()){
        return (pqmax.top()+pqmin.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){

   int n,k;
   cin>>n>>k;

   vector<int>a(n);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   priority_queue<int,vector<int>>pq;

   for(int i=0;i<n;i++){
    pq.push(a[i]);
   }int sum=0;
   int cnt=0;

   while(!pq.empty()){
    sum+=pq.top();
    pq.pop();
    cnt++;
    if(sum>=k){
        break;
    }
   }
   if(sum<k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<cnt<<endl;
    }

    return 0;
}