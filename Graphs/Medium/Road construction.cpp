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
multiset<int> ms;

void make(int n){
    par[n]= n;
    sz[n] =1;
    ms.insert(1);
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
        ms.erase(ms.find(sz[a]));
        ms.erase(ms.find(sz[b]));
        par[b] = a;
        sz[a] += sz[b];
        ms.insert(sz[a]);
    }
}


int main(){
    int n,m;cin>>n>>m;
    int ct= n;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v)){
            ct--;
        }
        Union(u,v);
        z(ct);
        c(*ms.rbegin());
    }
   

    return 0;
}