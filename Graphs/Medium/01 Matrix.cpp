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

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    int n= mat.size(),m= mat[0].size();
    // vector<vector<int>> ans(n,vi(m,0));
    vector<vector<int>> lev(n,vi(m,INT_MAX));
    vpii mov={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                lev[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pii pr= q.front();
        q.pop();
        for(auto &dir: mov){
            int nr= pr.first - dir.first;
            int nc= pr.second- dir.second;
            if(nr<0 || nc<0 || nr>=n || nc>= m){continue;}
            if(lev[pr.first][pr.second] + 1< lev[nr][nc]){
                q.push({nr,nc});
                lev[nr][nc] = lev[pr.first][pr.second] + 1;
            }
        }
    }
    return lev;
}

int main(){
    
    return 0;
}