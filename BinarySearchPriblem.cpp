#include<bits/stdc++.h>
using namespace std;

bool isfeasible(int mid,int arr[],int n,int m){

    int pos=arr[0];
    int elements=1;

    for(int i=0;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==m){
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[],int n,int k){

    sort(arr,arr+n);
    int result=-1;
    int left=1;
    int right=arr[n-1];
    while(left<right){
        int mid=(left+right)/2;

        if(isfeasible(mid,arr,n,k)){
            result=max(result,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return result;
}

bool ispossible(int arr[],int n,int m,int mid){
    int studentrequired=1;
    int sum=0;

    for(int i=0;i<n;i++){

        if(arr[i]>mid){
            return false;
        }
        if(sum+arr[i]>mid){
            studentrequired++;
            sum=arr[i];
            if(studentrequired>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }
    return true;
}


int allocateMin(int arr[],int n,int m){
    int sum=0;
    if(n<m){
        return -1;
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int start=0;
    int end=sum;
    int ans=INT_MAX;

    while(start<=end){
        int mid=(start+end)/2;

        if(ispossible(arr,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int findFeasible(int arr[],int n,int mid){
    int s=0;
    int painter=1;

    for(int i=0;i<n;i++){
        s+=arr[i];

        if(s>mid){
            s=arr[i];
            painter++;
        }
    }
    return painter;
}

int painterspartion(int arr[],int n,int m){
    int total;
    int k=0;

    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
        total+=arr[i];
    }

    int low=k;
    int high=total;

    while(low<high){
        int mid=(low+high)/2;
        int painters=findFeasible(arr,n,mid);

        if(painters<=m){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int searchInRotedArray(int arr[],int key,int left,int right){
    if(left>right){
        return -1;
    }

    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }

    if(arr[left]<=arr[mid]){
        if(key>=arr[left] && key<=arr[mid]){
            return searchInRotedArray(arr,key,left,mid-1);
        }
        return searchInRotedArray(arr,key,mid+1,right);
    }
    if(key>=arr[mid] && key<=arr[right]){
        return searchInRotedArray(arr,key,mid+1,right);
    }
    return searchInRotedArray(arr,key,left,mid-1);
}

int findPeakElement(int arr[],int low,int high,int n){
    int mid=low+(high-low)/2;

    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr,low,mid-1,n);
    }
    else{
        return findPeakElement(arr,mid+1,high,n);
    }
}

int main (){

    int arr[]={4,6,7,1,2,3};

    cout<<findPeakElement(arr,0,6,6)<<endl;

    return 0;
}