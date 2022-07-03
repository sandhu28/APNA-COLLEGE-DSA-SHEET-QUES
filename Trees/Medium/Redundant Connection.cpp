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
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

void make(vi &par,vi &sz,int n){
    par[n]=n;
    sz[n]=n;
}

int find(vi &par,vi &sz,int n){
    if(par[n]==n){
        return n;
    }
    return par[n]= find(par,sz,par[n]);
}

void Union(int a,int b,vi &par,vi &sz){
    a= find(par,sz,a);
    b= find(par,sz,b);
    if(a!=b){
        if(sz[a]<sz[b]){swap(a,b);}
        par[b]= a;
        sz[a]+= sz[b];
    }
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    int n= edges.size();
    vi ans;
    vi par(n+1,-1);
    vi sz(n+1,0);
    for(int i=1;i<=n;i++){
        make(par,sz,i);
    }
    for(int i=0;i<n;i++){
        auto v= edges[i];
        if(find(par,sz,v[0])== find(par,sz,v[1])){
            ans= v;break;
        }
        Union(v[0],v[1],par,sz);
    }
    return ans;
}
int main(){
    
    return 0;
}