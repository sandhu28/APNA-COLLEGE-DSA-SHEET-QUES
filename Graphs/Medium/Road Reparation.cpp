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
const int N= 1e5+ 3;
int sz[N];
int par[N];

void make(int n){
    par[n]= n;
    sz[n] =1;
}
int find(int a){
    if(par[a]== a){
        return a;
    }
    return par[a]= find(par[a]);
} 
void Union(int a,int b){
    a= find(a);
    b= find(b);
    if(a!= b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}


int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,pii>> edges;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back({w,{x,y}});
    }
    for(int i=1;i<=n;i++){
        make(i);
    }
    sort(edges.begin(),edges.end());
    lli cost=0;
    int ct=0;
    for(auto &edge: edges){
        int u= edge.second.first;
        int v= edge.second.second;
        int w= edge.first;
        if(find(u)!=find(v)){
            ct++;
            Union(u,v);
            cost = cost + 1LL*w;
        }
    }
    if(ct== n-1){
        c(cost);
    }
    else{
        c("IMPOSSIBLE");
    }

    return 0;
}