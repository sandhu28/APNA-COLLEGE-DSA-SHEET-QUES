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


bool isValid(int i,int j,int n){
    return (i>=0)&& (j>=0)&& (i<n)&& (j<n);
}

int maxDistance(vector<vector<int>>& grid) {

    queue<pii> q;
    int n= grid.size();
    vvi dist(n,vi(1e8));
    fo(i,n){
        fo(j,n){
            if(grid[i][j]==1){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }
    vpii dir1= {{1,0},{-1,0},{0,1},{0,-1}};
    vpii dir2= {{1,1},{1,-1},{-1,1},{-1,-1}};
    while(!q.empty()){
        auto pr= q.front();
        q.pop();
        int cr= pr.first,cc= pr.second;
        for(auto &p:dir1){
            int nr= cr-p.first;
            int nc= cc-p.second;
            if(!isValid(nr,nc,n)){continue;}
            if(dist[cr][cc]+1<dist[nr][nc]){
                dist[nr][nc]= dist[cr][cc]+1;
                q.push({nr,nc});
            }
        }
        for(auto &p:dir2){
            int nr= cr-p.first;
            int nc= cc-p.second;
            if(!isValid(nr,nc,n)){continue;}
            if(dist[cr][cc]+2<dist[nr][nc]){
                dist[nr][nc]= dist[cr][cc]+1;
                q.push({nr,nc});
            }
        }
    }
    int mxDist= INT_MIN;
    fo(i,n){
        fo(j,n){
            if(grid[i][j]==0){
                mxDist= max(mxDist,dist[i][j]);
            }
        }
    }
    return mxDist;
        
}

int main(){
    
    return 0;
}