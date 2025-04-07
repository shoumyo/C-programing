#include<iostream>
#include<cmath>
#include <math.h>
#include<bits/stdc++.h>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

//Rat in Maze problem

bool isSafe1(int **arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

int ratinMaze(int **arr,int x,int y,int n,int **solveArr){
    if(x==n-1 && y==n-1){
        solveArr[x][x]=1;
        return true;
    }
    if(isSafe1(arr,x,y,n)){
        solveArr[x][y]=1;
     if(ratinMaze(arr,x+1,y,n,solveArr)){
         return true;
     }
     if(ratinMaze(arr,x,y+1,n,solveArr)){
         return true;
     }
     solveArr[x][y]=0;
     return false;
    }
    return false;
}

//N Queen Problem

bool isSafe2(int **arr,int x,int y,int n){
    for(int i=0;i<x;i++){
        if(arr[i][y]==1){
            return false;
        }
    }

    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr,int x,int n){
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe2(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }
    return false;

}

int main(){

    int n;
    cin>>n;

    int **arr=new int *[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}