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

int main(){
    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[i]=x;
    }
    map<int,pii> m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(m.count(x-v[i]-v[j])){
                z(i+1);z(j+1);z(m[x-v[i]-v[j]].first+1);c(m[x-v[i]-v[j]].second+1);
                return 0;
            }
        }
        for(int j=0;j<i;j++){
            m.insert({v[i]+v[j],{j,i}});
        }
    }
    c("IMPOSSIBLE");

    return 0;
}