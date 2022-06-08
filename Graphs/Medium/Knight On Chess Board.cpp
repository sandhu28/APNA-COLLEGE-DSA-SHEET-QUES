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

vector<pair<int,int>> mov={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

int bfs(int a, int b, int c, int d, int e, int f){
    queue<pair<int,int>> q;
    int vis[a+1][b+1];
    q.push({c,d});vis[c][d]=1;
    while(!q.empty()){
        auto pr= q.front();
        q.pop();
        for(auto &dir: mov){
            int nr= pr.first - dir.first;
            int nc= pr.second - dir.second;
            if((nr<1 || nc<1 || nr>a || nc>b) || (vis[nr][nc]!=0)){
                continue;
            }
            q.push({nr,nc});
            vis[nr][nc] = vis[pr.first][pr.second] + 1;
            if(nr==e && nc==f){
                return vis[nr][nc];
            }
        }
    }
    return -1;
}
int knight(int a, int b, int c, int d, int e, int f) {
    return bfs(a,b,c,d,e,f);
}

int main(){
    
    return 0;
}