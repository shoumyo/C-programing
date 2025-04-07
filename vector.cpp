#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool myCompare(pair<int,int>p1,pair<int,int>p2){
    return p1.first<p2.first;
}

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void countSort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[k]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=0;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void dnfSort(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
             low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}

void waveSort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr,i,i+1);
        }
    }
}

long long merge(int arr[],int l,int mid,int r){
    long long inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            inv+=n1-i;
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    return inv;
}

long long mergesort(int arr[],int l,int r){
    long long inv=0;

    if(l<r){
        int mid=(l+r)/2;
        inv+=mergesort(arr,l,mid);
        inv+=mergesort(arr,mid+1,r);
        inv+=merge(arr,l,mid,r);
    }
    return inv;
}

int main(){

  int arr[]={3,5,6,9,1,2,7,8};

  cout<<mergesort(arr,0,7)<<endl;

  

    return 0;
}