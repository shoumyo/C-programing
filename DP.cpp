#include<bits/stdc++.h>
using namespace std;

int dp[200][200][200];
int n,m,k;
vector<int>a,b;

int solve(int i,int j,int k){
    if(i==n || j==m){
        return 0;
    }

    if(dp[i][j][k] !=-1){
        return dp[i][j][k];
    }
}

int main(){

    memset(dp,-1,sizeof(dp));

    cin>>n>>m>>k;

    a=vector<int>(n);
    b=vector<int>(m);

    for(auto &i : a){
        cin>>i;
    }

    for(auto &i : b){
        cin>>i;
    }

    cout<<solve(0,0,k);

    return 0;
}