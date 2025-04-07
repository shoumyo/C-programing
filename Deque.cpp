#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int get_max_area(vector<int>a){
    int n=a.size();
    int ans=0;
    int i=0;
    stack<int>st;
    a.push_back(0);

    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int t=st.top();
            int h=a[t];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int rain_water(vector<int>a){
    stack<int>st;
    int n=a.size();
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() and a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i]-a[cur]))*diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){

    vector<int>a={0,1,0,2,1,0,1,3,2,2,1,2,1};
    cout<<rain_water(a)<<endl;

   
    return 0;
}