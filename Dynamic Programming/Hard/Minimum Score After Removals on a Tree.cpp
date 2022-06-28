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

int dfs(vvi &g,vi &val,int i,vi &vis,vi &par,vpii &pc,vvi &child_par,vi &nums)
{
    vis[i] =1;
    val[i]=nums[i];
    for(auto &p: par){
        child_par[p][i] = 1;
    }
    par.push_back(i);
    for(auto &child: g[i]){
        if(!vis[child]){
            pc.push_back({i,child});
            val[i] ^= dfs(g,val,child,vis,par,pc,child_par,nums);
        }
    }
    par.pop_back();
    return val[i];

}
int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n= nums.size();
    vvi g(n);
    vi xor_val(n);
    vi vis(n,0);
    vi par(n,0);
    vpii pc;
    vvi child_par(n,vi(n,0));
    for(auto &edge:
     edges){
        int u=edge[0],v= edge[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(g,xor_val, 0,vis,par,pc,child_par,nums);
    int ans= INT_MAX;
    for(int i=0;i<pc.size();i++){
        for(int j=i+1;j<pc.size();j++){
            int a= pc[i].second;
            int b= pc[j].second;
            int xa= xor_val[a];
            int xb= xor_val[b];
            int xc= xor_val[0];
            
            if(child_par[a][b]){
                xc ^= xa;
                xa ^= xb;
            }
            else{
                xc ^= xa;
                xc ^= xb;
            }
            
            ans= min(ans, max(xa,max(xb,xc)) - min(xa,min(xb,xc)));
        }
    }
    return ans;
}

int main(){
    
    return 0;
}