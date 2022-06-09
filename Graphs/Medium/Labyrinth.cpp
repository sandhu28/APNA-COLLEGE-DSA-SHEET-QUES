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
const int N= 1e3+ 2;

vpii mov={{0,1},{0,-1},{1,0},{-1,0}};

bool isValid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}

int bfs(vector<vector<char>> &g,int n,int m,vvi &lev,int si,int sj,int fi,int fj,vector<vector<char>> &dir){
    queue<pii> q;
    q.push({si,sj});
    lev[si][sj] =0;
    while(!q.empty()){
        auto pr= q.front();
        int ci= pr.first;int cj= pr.second;
        q.pop();
        for(auto &move: mov){
            int nr= ci- move.first;
            int nc= cj - move.second;
            if((isValid(nr,nc,n,m)) && (g[nr][nc]!='#') && (lev[ci][cj] + 1 < lev[nr][nc])){
                lev[nr][nc] = lev[ci][cj] + 1;
                q.push({nr,nc});
                if(move.first==0 && move.second==1){
                    dir[nr][nc]='R';
                }
                else if(move.first==0 && move.second==-1){
                    dir[nr][nc]='L';
                }
                else if(move.first==1 && move.second==0){
                    dir[nr][nc] = 'D';
                }
                else {
                    dir[nr][nc] = 'U';
                }
                if(nr== fi && nc== fj){
                    cout<<"YES"<<endl;
                    return lev[nr][nc];
                }
            }
        }

    }
    c("NO");
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<char>> dir(n,vector<char>(m));
    int si,sj,fi,fj;
    rep(i,0,n){
        rep(j,0,m){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                si=i;sj=j;
            }
            if(g[i][j]=='B'){
                fi=i;fj=j;
            }
        }
    }
    vvi lev(n,vi(m,INF));
    int temp = bfs(g,n,m,lev,si,sj,fi,fj,dir);
    if(temp==-1){return 0;}
    c(temp);
    int i= fi,j=fj;
    vector<char> ans;
    while((i!=si) || (j!=sj)){
        if(dir[i][j]=='U'){
            i--;
            ans.push_back('D');
        }
        else if(dir[i][j]=='D'){
            i++;
            ans.push_back('U');
        }
        else if(dir[i][j]=='L'){
            j--;
            ans.push_back('R');
        }
        else{
            j++;
            ans.push_back('L');
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto &ch: ans){
        cout<<ch;
    }
    return 0;
}