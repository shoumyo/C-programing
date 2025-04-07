#include<bits/stdc++.h>
using namespace std;

void maxSubarraySum(int arr[],int n,int k,int x){
    int sum=0;
    int ans=0;

    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum<x){
        ans=sum;
    }

    for(int i=k;i<n;i++){
        sum=sum-arr[i-k];
        sum=sum+arr[i];

        if(sum<x){
            ans=max(sum,ans);
        }
    }
    cout<<ans<<endl;
}

int smallestSubarraySize(int arr[],int n,int x){
    int ans=INT_MAX;
    int sum=0;
    int minLength=n+1;
    int start=0;
    int end=0;

    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        while(sum>x && start<n){
            if(end-start<minLength){
                minLength=end-start;
            }
            sum-=arr[start++];
        }
    }
    return minLength;
}

void computeSubarraySub(vector<int>arr,int k){
    pair<int,int>ans;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    bool found=false;

    if(sum%3==0){
        ans=make_pair(0,k-1);
        found=true;
    }
    for(int j=k;j<arr.size();j++){
        if(found){
            break;
        }
        sum=sum+arr[j]-arr[j-k];
        if(sum%3==0){
            ans=make_pair(j-k+1,j);
            found=true;
        }
    }
    if(!found){
        ans=make_pair(-1,0);
    }
    if(ans.first==-1){
        cout<<"Not found"<<endl;
    }
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<arr[i]<<"";
        }
        cout<<endl;
    }
}

bool isPalindrome(int num){
    int temp=num;
    int number=0;

    while(temp>0){
        number=number*10+temp%10;
        temp=temp/10;
    }
    if(number==num){
        return true;
    }
    return false;
}


int findPalindrommicSubarray(vector<int>arr,int k){

    int num=0;
    for(int i=0;i<k;i++){
        num=num*10+arr[i];
    }
    if(isPalindrome(num)){
        return 0;
        //The starting value is 0 :)
    }

    for(int j=k;j<arr.size();j++){
        num=(num %(int)pow(10,k-1))*10+arr[j];

        if(isPalindrome(num)){
            return j-k+1;
        }
    }
    return -1;
}

bool isNumPerfect(int n){
    int sum=1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            sum+=n/i;
        }
    }
    if(sum==n && n!=1){
        return true;
    }
    return false;
}

int maxsum(int arr[],int n,int k){
    if(n<k){
        cout<<"Invalid values"<<endl;
        return -1;
    }
    int res=0;
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sum=res;
    for(int i=k;i<n;i++){
        sum+=arr[i]-arr[i-k];
        res=max(res,sum);
    }
    return res;
}

int maxNumberPerfect(int arr[],int n,int k){

    for(int i=0;i<n;i++){
        if(isNumPerfect(arr[i])){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
    return maxsum(arr,n,k);
}


int main(){
   int arr[]={28,2,3,6,496,99,8128,24};
   int n=8;
   int k=4;

   int x=maxNumberPerfect(arr,n,k);

   if(x==0){
    cout<<"no elements found"<<endl;
   }
   else{
    cout<<x<<endl;
   }
    return 0;
}