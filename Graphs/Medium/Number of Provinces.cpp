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

void make(int n,vi &par,vi &sz){
    par[n]=n;
    sz[n] =1;
}
int find(int n,vi &par, vi&sz){
    if(par[n]==n){
        return n;
    }
    return par[n] = find(par[n],par,sz);
}
void Union(int a,int b,vi &par,vi &sz){
    a= find(a,par,sz);
    b= find(b,par,sz);
    if(a!= b){
        if(sz[a]< sz[b]){swap(a,b);}
        par[b] = a;
        sz[a]+= sz[b];
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n= isConnected.size(); 
    vi par(n+1,-1);
    vi sz(n+1,0);
    for(int i=1;i<=n;i++){
        make(i,par,sz);
    }
    // rep(i,0,n+1){
    //     z(par[i]);
    //     c(sz[i]);
    // }
    // nl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && (i!=j)){
                Union(i+1,j+1,par,sz);
            }
        }
    }
    // rep(i,0,n+1){
    //     z(par[i]);
    // }
    // nl;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(par[i]==i){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vvi v(n,vi(n,0));
    rep(i,0,n){
        rep(j,0,n){
            cin>>v[i][j];
        }

    }
    // c("yes");
    c(findCircleNum(v));
    
    return 0;
}