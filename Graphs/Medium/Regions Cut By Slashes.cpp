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

class Solution {
public:

    vpii dir= {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vvi &mat,int i,int j,int n, vvi &vis){
        vis[i][j]=1;
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j]=='0'){
            return;
        }
        for(auto &pr: dir){
            int nr=i-pr.first;
            int nc= j- pr.second;
            if(vis[nr][nc]){
                continue;
            }
            dfs(mat,nr,nc,n,vis);
        }

    }

    int regionsBySlashes(vector<string>& grid) {
        int n= grid.size();
        vvi mat(n*3,vi(n*3,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=mat[i*3+1][j*3+1]=mat[i*3+2][j*3]=0;
                }
                if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=mat[i*3+1][j*3+1]=mat[i*3+2][j*3+2]=0;
                }
            }
        }
        int ct=0;
        vvi vis(n*3,vi(n*3,0));
        int N= n*3;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]=='1' && vis[i][j]==0){
                    dfs(mat,i,j,N,vis);
                    ct++;
                }
            }
        }
        return ct;

    }
};

int main(){
    
    return 0;
}