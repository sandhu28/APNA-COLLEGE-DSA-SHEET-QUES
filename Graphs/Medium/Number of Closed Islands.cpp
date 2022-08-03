#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

bool isValid(int i,int j,int n,int m){
    return (i>=0)&& (j>=0)&& (i<n)&& (j<m);
}

vpii mov= {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int i,int j,vvi &grid,vvi &vis,bool &f){
    int n= grid.size();
    int m= grid[0].size();
    vis[i][j]=1;
    for(auto &pr: mov){
        int ni= i-pr.first;
        int nj= j- pr.second;
        if(!isValid(ni,nj,n,m) && grid[i][j]==0){
            f=0;
            continue;
        }
        if(!isValid(ni,nj,n,m)){continue;}
        if(grid[ni][nj]==1){continue;}
        if(vis[ni][nj]==1){continue;}
        dfs(ni,nj,grid,vis,f);
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int rows= grid.size();
    int cols= grid[0].size();
    vvi vis(rows,vi(cols,0));
    int ans=0;
    fo(i,rows){
        fo(j,cols){
            if(grid[i][j]==0 && vis[i][j]==0){
                bool f=1;
                dfs(i,j,grid,vis,f);
                if(f){ans++;}
            }
        }
    }
    return ans;
}

int main(){
    
    return 0;
}