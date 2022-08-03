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

void dfs(vi &g,vi &isPre,vi &vis,int ans,int node,stack<int> &stk,int idx){
    vis[node]=1;
    stk.push(node);
    isPre[node]= idx;
    int child= g[node];
    if(child==-1){return;}
    if(vis[child]==1 && isPre[child]!=-1){
        ans= max(ans,idx- isPre[child]+1);
    }
    if( !vis[child]){
        dfs(g,isPre,vis,ans,child,stk,idx+1);
    }
    isPre[node]=-1;
    stk.pop();

}

int longestCycle(vector<int>& g) {
    int n= g.size();
    vi isPre(n,-1);
    vi vis(n,0);
    stack<int> stk;
    int ans= INT_MIN;
    int idx=0;
    dfs(g,isPre,vis,ans,0,stk,idx);
    return ans;

}

int main(){
    
    return 0;
}