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
    int n,q;cin>>n>>q;
    vi v(n+1);
    rep(i,1,n+1){
        cin>>v[i];
    }
    v[0]=0;
    vlli prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]= 1LL*v[i] + prefix[i-1];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        c(prefix[y]- prefix[x-1]);
    }

    return 0;
}