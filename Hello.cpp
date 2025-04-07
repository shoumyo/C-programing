#include<bits/stdc++.h>
using namespace std;


class student{
    private:
    vector<vector<int>>numbers;
    vector<int>ans;
    public:
    
    void input(vector<vector<int>>&a,int n){
       for(int i=0;i<n;i++){
           for(int j=0;j<5;j++){
               numbers[i][j]=a[i][j];
               ans[i]+=a[i][j];
           }
       }
    }
    
    int total(int n){
        return ans[n-1];
    }
};

int main() {
    
    int n;
    cin>>n;
    vector<vector<int>>a;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    student s;
    s.input(a,n);
    int count=0;
    
    for(int i=2;i<=n;i++){
        if(s.total(1)>s.total(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
