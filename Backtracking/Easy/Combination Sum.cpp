#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool recur(vi& v,int i,int n,int k,vector<vector<int>> &ans,vi &vec){
    if(k==0){
        ans.push_back(vec);
        return 1;
    }
    if(i==n){
        return false;
    }
    bool check=0;
    if(v[i]<=k){
        vec.push_back(v[i]);
        check |= recur(v,i,n,k-v[i],ans,vec);
        vec.pop_back();
    }
    check |= recur(v,i+1,n,k,ans,vec);
    return check;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n= candidates.size();
    vector<vector<int>> ans;
    vi vec;
    recur(candidates,0,n,target,ans,vec);
    return ans;
}

int main(){
    
    return 0;
}