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

bool ratInMaze(vector<vector<int>> &v,int n,vector<string> &ans,int i,int j,string &s,vector<vector<int>> &vis){

    if((i<0 || i>=n || j<0 || j>=n) || (v[i][j]==0) || (vis[i][j]==1)){
        return 0;
    }
    if(i==n-1 && j==n-1){
        ans.push_back(s);
        return 1;
    }
    vis[i][j]=1;
    s+= 'R';
    bool right = ratInMaze(v,n,ans,i,j+1,s,vis);
    s.pop_back();
    s+= 'D';
    bool down= ratInMaze(v,n,ans,i+1,j,s,vis);
    s.pop_back();
    s+= 'U';
    bool up = ratInMaze(v,n,ans,i-1,j,s,vis);
    s.pop_back();
    s+= 'L';
    bool left= ratInMaze(v,n,ans,i,j-1,s,vis);
    s.pop_back();
    vis[i][j]=0;
    return down | right | left | up;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(m[0][0]==0){
        return ans;
    }
    string s="";
    ratInMaze(m,n,ans,0,0,s,vis);
    return ans;
}
int main(){
    int n;cin>>n;
    vvi v(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    auto ans= findPath(v,n);
    for(auto& e:ans){
        c(e);
    }
    return 0;
}