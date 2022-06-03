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
    vpii v;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        v.push_back({k,i});
    }
    sort(v.begin(),v.end());
    int l=0,h= n-1;
    bool t= true;
    while(l<h){
        int sm= v[l].first+v[h].first;
        if(sm==x){
            z(v[l].second + 1);c(v[h].second+1);
            t= false;
            break;
        }
        else if(sm<x){
            l++;
        }
        else{
            h--;
        }

    }
    if(t){
        c("IMPOSSIBLE");
    }
    return 0;
}