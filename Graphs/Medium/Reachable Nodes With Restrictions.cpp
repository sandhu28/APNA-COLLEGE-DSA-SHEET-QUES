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
#define vs vector<string>
#define ss second
#define ff first
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

void dfs(int &ans,int i,vvi &g,vi &res,int par){
    if(res[i]){
        return;
    }
    ans++;
    for(auto &child: g[i]){
        if(child== par){
            continue;
        }
        dfs(ans,child,g,res,par);
    }
}

int reachableNodes(int n, vector<vector<int>>& e, vector<int>& res) {    
    vvi g(n);
    for(int i=0;i<n-1;i++){
        g[e[i][0]].push_back(e[i][1]);
        g[e[i][1]].push_back(e[i][0]); 
    }
    int N= 1e5+2;
    vi r(N,0);
    for(int i=0;i<res.size();i++){
        r[res[i]]=1;
    }
    int ans=0;
    dfs(ans,0,g,r,-1);
    return ans;

        
}

int main(){
    
    return 0;
}