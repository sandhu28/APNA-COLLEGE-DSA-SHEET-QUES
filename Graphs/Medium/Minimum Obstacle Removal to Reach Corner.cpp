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

vpii mov= {{0,1},{0,-1},{1,0},{-1,0}};

bool isValid(int i,int j, int m,int n){
    return (i>=0) && (j>=0) && i<m && (j<n);
}

int minimumObstacles(vector<vector<int>>& grid) {
    int m= grid.size();
    int n= grid[0].size();
    vvi lev(m,vi(n,INF));
    deque<pii> dq;
    lev[0][0] =0;
    dq.push_front({0,0});
    while(!dq.empty()){
        auto pr= dq.front();
        dq.pop_front();
        for(auto &dir : mov){
            int nr= pr.first- dir.first;
            int nc= pr.second- dir.second;
            if(!isValid(nr,nc,m,n)){continue;}
            if(grid[nr][nc]==1){
                if(lev[nr][nc]> lev[pr.first][pr.second] + 1){
                    lev[nr][nc] = lev[pr.first][pr.second] + 1;
                    dq.push_back({nr,nc});
                }
            }
            else{
                if(lev[nr][nc] > lev[pr.first][pr.second]){
                    lev[nr][nc] = lev[pr.first][pr.second];
                    dq.push_front({nr,nc});
                }
            }
        }
        
    }
    return lev[m-1][n-1];

}

int main(){
    
    return 0;
}