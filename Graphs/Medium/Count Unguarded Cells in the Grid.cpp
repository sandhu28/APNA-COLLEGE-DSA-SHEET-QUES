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

bool isValid(int m,int n,int i,int j){
    return (i<m) && (j<n) &&(i>=0) &&(j>=0);
}
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vvi g(m,vi(n,0));
    vvi w(m,vi(n,0));
    for(auto &v: guards){
        g[v[0]][v[1]]=1;
    }
    for(auto &v: walls){
        w[v[0]][v[1]] = 1;
    }
    vvi vis(m,vi(n,0));
    for(int i=0;i<guards.size();i++){
        int x= guards[i][0],y= guards[i][1];
        /// right
        while(1){
            if((isValid(m,n,x,y+1)==1) && (g[x][y+1]==0) && (w[x][y+1]==0)){
                vis[x][y+1]=1;
                y++;
            }
            else{
                break;
            }
        }
        while(1){
            if((isValid(m,n,x,y-1)==1) && (g[x][y-1]==0) && (w[x][y-1]==0)){
                vis[x][y-1]=1;
                y--;
            }
            else{
                break;
            }
        }
        while(1){
            if((isValid(m,n,x+1,y)==1) && (g[x+1][y]==0) && (w[x+1][y]==0)){
                vis[x+1][y]=1;
                x++;
            }
            else{
                break;
            }
        }
        while(1){
            if((isValid(m,n,x-1,y)==1) && (g[x-1][y]==0) && (w[x-1][y]==0)){
                vis[x-1][y]=1;
                x--;
            }
            else{
                break;
            }
        }
    }
    int ct=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==0 && (w[i][j]==0) && (vis[i][j]==0)){
                ct++;
            }
        }
    }
    return ct;
}

int main(){
    
    return 0;
}