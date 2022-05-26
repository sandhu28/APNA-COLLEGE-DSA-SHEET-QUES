#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

vector<int> twoSum(vector<int>& v, int k) {
    unordered_map<int,int> um;
    int n= v.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int to_find = k- v[i];
        if(um.find(to_find)!=um.end()){
            ans.push_back(um[to_find]);
            ans.push_back(i);
            break;
        }
        um[v[i]]=i;
    }
}

int main(){
    
    return 0;
}