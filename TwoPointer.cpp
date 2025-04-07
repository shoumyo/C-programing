#include<bits/stdc++.h>
using namespace std;

bool found(vector<int>a,int n,int key){
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int lo=i+1;
        int hi=n-1;
        while(lo<hi){
            int current=a[i]+a[lo]+a[hi];
            if(current==key){
                return true;
            }
            if(current<key){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    return false;
}

int maximumConsecutive(vector<int>a,int n,int key){

    int zerocount=0,ans=0,i=0;

    for(int j=0;j<n;j++){
        if(a[j]==0){
            zerocount++;
        }
        while(zerocount>key){
            if(a[i]==0){
                zerocount--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}

int longSubstring(string s){
    vector<int>dict(256,-1);
    int maxlen=0;
    int start=-1;

    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>start){
            start=dict[s[i]];
        }
        dict[s[i]]=i;
        maxlen=max(maxlen,i-start);
    }
    return maxlen;
}


int  main(){

    string s;
    cin>>s;

    cout<<longSubstring(s)<<endl;

    return 0;
}    