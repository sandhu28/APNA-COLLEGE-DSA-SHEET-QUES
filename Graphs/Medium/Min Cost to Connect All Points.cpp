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

int minCostConnectPoints(vector<vector<int>>& points) {
    int n= points.size();
    vector<pair<int,pii>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int w= abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({w,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    vi par(n,-1);
    vi sz(n,0);
    for(int i=0;i<n;i++){
        make(i,par,sz);
    }
    int totalCost=0;
    for(int i=0;i<edges.size();i++){
        int w= edges[i].first;
        int u= edges[i].second.first;
        int v= edges[i].second.second;
        if(find(u,par,sz) == find(v,par,sz)){continue;}
        Union(u,v,par,sz);
        totalCost+= w;
    }
    return totalCost;

}

int main(){
    
    return 0;
}