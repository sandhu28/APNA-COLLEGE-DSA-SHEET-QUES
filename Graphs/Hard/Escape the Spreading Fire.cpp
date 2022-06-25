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
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

vpii mov={{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int i,int j,int m,int n){
    return (i>=0) && (j>=0) && (i<m) && (j<n);
}

void calc_fire(vvi &grid,vvi &fire,int m,int n){
    queue<pii> q;
    // vvi lev(m,vi(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                fire[i][j]=0;
                // vis[i][j] =0;
            }
        }
    }
    while(!q.empty()){
        auto pr= q.front();
        int cr= pr.first,cc= pr.second;
        q.pop();
        for(auto &dir: mov){
            int nr= cr-dir.first,nc= cc- dir.second;
            if(!isValid){continue;}
            if(grid[nr][nc]==2){continue;}
            if(fire[nr][nc]> fire[cr][cc] + 1){
                fire[nr][nc] = fire[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }
}

void calc_person(vvi &grid,vvi &person,int m,int n){
    queue<pii> q;
    // vvi lev(m,vi(n,0));
    q.push({0,0});
    person[0][0] = 0;
    while(!q.empty()){
        auto pr= q.front();
        int cr= pr.first,cc= pr.second;
        q.pop();
        for(auto &dir: mov){
            int nr= cr-dir.first,nc= cc- dir.second;
            if(!isValid){continue;}
            if((grid[nr][nc]==2) || (grid[nr][nc]==1)){continue;}
            if(person[nr][nc]> person[cr][cc] + 1){
                person[nr][nc] = person[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }
}

int maximumMinutes(vector<vector<int>>& grid) {
    int m= grid.size(),n= grid[0].size();
    vvi fire(m,vi(n,INF));
    vvi person(m,vi(n,INF));
    calc_fire(grid,fire,m,n);
    calc_person(grid,person,m,n);

    if(person[m-1][n-1]>=INF){
        return -1;
    }
    if(fire[m-1][n-1]>=INF){
        return 1e9;
    }
    int diff_safehouse= fire[m-1][n-1] - person[m-1][n-1];
    if(diff_safehouse<=0){return -1;}

    int diff_lft= -1,diff_rght= -1;
    if((person[m-2][n-1]<INF) && (fire[m-2][n-1]<INF)){
        diff_lft = fire[m-2][n-1] - person[m-2][n-1];
    }
    if((person[m-1][n-2]<INF) && (fire[m-1][n-2]<INF)){
        diff_rght = fire[m-1][n-2] - person[m-1][n-2];
    }
    if((diff_lft > diff_safehouse) || (diff_rght> diff_safehouse)){
        return diff_safehouse;
    }
    return diff_safehouse-1;
    
}

int main(){
    
    return 0;
}