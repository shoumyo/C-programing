#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

void primeSieve(int n){
    int prime[100]={0};
    for(int i=2;i<n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
            prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void primefactor(int n){
    int spf[100]={0};
    for(int i=2;i<n;i++){
        spf[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;i<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    cout<<endl;
}

int divisible(int n,int a,int b){
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);

    return c1+c2-c3;
}

int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

//recursion starts from here...

int sumofNaturalN(int n){

    if(n==0){
        return 0;
    }
    int prevSum=sumofNaturalN(n-1);
    return n+prevSum;
    }

 int raisedpower(int n,int p){
        if(p==0){
            return 1;
        }
        int pervpow=raisedpower(n,p-1);
        return n*pervpow;
    }

 int factorial(int n){

        if(n==0){
            return 1;
        }
        int prevfact=factorial(n-1);
        return n*prevfact;
    }

 int printNthFibonacci(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        int fib1=printNthFibonacci(n-1);
        int fib2=printNthFibonacci(n-2);
        int ans=fib1+fib2;
        return ans;
    }

 bool sorted(int arr[],int n){
        if(n==1){
            return true;
        }
        bool restarray=sorted(arr+1,n-1);
        if(arr[0]<arr[1] && restarray){
            return true;
        }
        return false;
    }

 int printInDereasingOrder(int n){
        if(n==0){
            return 0;
        }
        cout<<n<<" ";
        printInDereasingOrder(n-1);
    }

 int printInIncreasingOrder(int n){
        if(n==0){
            return 0;
        }
        printInIncreasingOrder(n-1);
        cout<<n<<" ";
    }

int firstocc(int arr[],int i ,int n,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,i+1,n,key);
}

int lastocc(int arr[],int i,int n,int key){
    if(i==n){
        return -1;
    }
    int restarray=lastocc(arr,i+1,n,key);
    if(restarray !=-1){
        return restarray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}

void reverse(string s){
    if(s.length()==0){
        return;
    }
    string str=s.substr(1);
    reverse(str);
    cout<<s[0];
}

void replacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<3.14;
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

//This data stucture is beautiful :-)
void towerofHannoi(int n,char src,char dest,char helper){
    if(n==0){
        return;
    }
    towerofHannoi(n-1,src,helper,dest);  
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHannoi(n-1,helper,dest,src);
}

string removeDuplicate(string s){
    if(s.size()==0){
        return "\0";
    }

    char ch=s[0];
    string ans=removeDuplicate(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

string moveAll(string s,char ch){
    if(s.size()==0){
        return "\0";
    }
    char x=s[0];
    string ans=moveAll(s.substr(1),ch);
    if(x==ch){
        return ans+x;
    }
    return x+ans;
}

void subseq(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}

void subseqASCII(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);
    subseqASCII(ros,ans);
    subseqASCII(ros,ans+ch);
    subseqASCII(ros,ans+to_string(code));
}

string keypadArr[]={" ",",.;'[]-","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=keypadArr[ch-'0'];
    string ros=s.substr(1);
    for(int i=0;i<code.size();i++){
        keypad(ros,ans+code[i]);
    }
}

void permutation(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i ];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutation(ros,ans+ch);
    }
}

int countpath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=countpath(s+i,e);
    }
    return count;
}

//n is number of maze and i&j is location
int countopathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countopathMaze(n,i+1,j)+countopathMaze(n,i,j+1);
}

int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingWays(n-1)+tilingWays(n-2);
}

int friendsPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}

int knapsack(int value[],int wt[],int n,int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value,wt,n-1,W);
    }
    return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value,wt,n-1,W));
}

//Merge sort

void Merge(int arr[],int l,int mid,int r){
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

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        Merge(arr,l,mid,r);
    }
}

//Quick Sort

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void QuickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,r);
    }
}

int main(){

   int n;
   cin>>n;
   cout<<printNthFibonacci(n)<<endl;;
  
    return 0;
}