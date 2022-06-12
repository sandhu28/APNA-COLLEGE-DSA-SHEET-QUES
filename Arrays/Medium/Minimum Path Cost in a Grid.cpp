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

int recur(vvi &grid, vvi &cost,int i,int j,vvi &memo){
    int m= grid.size();
    int n= grid[0].size();
    int r= cost.size();
    int c= cost[0].size();
    if(i== m-1){
        return grid[i][j];
    }
    if(memo[i][j]!= -1){
        return memo[i][j];
    }
    int mn= INT_MAX;
    for(int col=0;col<n;col++){
        int curr= grid[i][j] + cost[grid[i][j]][col] + recur(grid,cost,i+1,col,memo);
        mn= min(mn,curr);
    }
    return memo[i][j] = mn;

}

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m= grid.size();
    int n= grid[0].size();
    int r= moveCost.size();
    int c= moveCost[0].size();
    vvi memo(m,vi(n,-1));
    int mn= INT_MAX;
    for(int i=0;i<n;i++){
        int curr= recur(grid,moveCost,0,i,memo);
        mn= min(mn, curr);
    }
    return mn;
}

int main(){
    
    return 0;
}