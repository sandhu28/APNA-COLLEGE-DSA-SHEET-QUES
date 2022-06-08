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

vector<pii> mov= { {1,0},{-1,0},{0,1},{0,-1}};
bool isValid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int r= heights.size(),c= heights[0].size();
    map<pii,vector<pair<pii,int>>> m;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(auto &pr:mov){
                int nr= i- pr.first;
                int nc= j- pr.second;
                if(isValid(nr,nc,r,c)){
                    m[{i,j}].push_back({{nr,nc},abs(heights[i][j]- heights[nr][nc])});
                }
            }
        }
    }
    set<pair<lli,pii>> s;
    vector<vector<bool>> vis(r,vector<bool>(c,0));
    vector<vector<lli>> dist(r,vector<lli>(c,LLONG_MAX));
    s.insert({0,{0,0}});
    while(!s.empty()){
        auto pr= *s.begin();
        s.erase(s.begin());
        int cd= pr.first,ci= pr.second.first,cj= pr.second.second;
        if(vis[ci][cj]){continue;}
        for(auto &child: m[{ci,cj}]){
            int w= child.second;
            int nr= child.first.first, nc= child.first.second;
            if((cd*1LL + 1LL*w) < dist[nr][nc]){
                dist[nr][nc] = (cd*1LL + 1LL*w);
                s.insert({dist[nr][nc],{nr,nc}});
            }
        }
        vis[ci][cj]=1;
    }
    return (int)dist[r-1][c-1];
}

int main(){

    set<int> one= {1,2,3};
    set<int> two = one;
    for(auto &p: two){
        c(p);
    }
    
    return 0;
}