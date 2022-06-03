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
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    li sm=0;
    li mx_sm=INT_MIN;
    // int n= v.size();
    for(int i=0;i<n;i++){
        sm+= v[i];
        mx_sm= max(mx_sm, sm);
        if(sm<0){
            sm=0;
        }
    }
    cout<<mx_sm<<endl;
    return 0;
}