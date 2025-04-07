#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

//binary coount always counts from right

bool getBit(int n,int pos){

    return(n & (1<<pos)!=0);

}

int setBit(int n,int pos){

    return (n | (1<<pos));
}

int clearBit(int n,int pos){
    int mask=~(1<<pos);
    return (n & mask);
}

int updateBit(int n,int pos,int value){
    int mask=~(1<<pos);
    n=n&mask;
    return (n|(value<<pos));
}

int unique(int arr[],int n){

    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit !=1){
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int Tunique(int arr[],int n){
    for(int i=0;i<64;i++){
        int sum=0;
        int result =0;
        for(int j=0;j<n;j++){
             if(getBit(arr[j],i)){
                sum++;
             }
        }
        if(sum%3!=0){
            result=setBit(result,i);
        }
        return result;
    }

}



int main(){

    int arr[]={1,2,3,4,1,2,3,1,2,3};
    cout<<Tunique(arr,10)<<endl;

    return 0;
}