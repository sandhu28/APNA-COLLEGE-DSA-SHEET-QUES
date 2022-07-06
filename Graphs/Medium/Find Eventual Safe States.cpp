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

void dfs(vvi &g,vi &vis,int i,stack<int> &stk,vi &isPre,vi &notInc){

    stk.push(i);
    vis[i]=1;
    isPre[i] = 1;
    for(auto &e: g[i]){
        if(vis[e] && isPre[e]){notInc[i]=1;continue;}
        if(vis[e]){continue;}
        dfs(g,vis,e,stk,isPre,notInc);
        if(notInc[e]){
            notInc[i] =1;
        }
    }
    stk.pop();
    isPre[i]=0;
    return ;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    int n= graph.size();
    stack<int> stk;
    vi vis(n,0);
    vi isPre(n,0);
    vi partOfCycle(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(graph,vis,i,stk,isPre,partOfCycle);
        }
    }
    vi ans;
    for(int i=0;i<n;i++){
        if(!partOfCycle[i]){
            ans.push_back(i);
        }
    }
    return ans;

}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    int n= graph.size();
    vvi revGraph;
    vi indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto &e: graph[i]){
            revGraph[e].push_back(i);
            indeg[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vi ans;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        ans.push_back(node);
        for(auto &child:revGraph[node]){
            if(--indeg[child]==0){
                q.push(child);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;

}

int main(){
    // int k= 19;
    // int p= ~k;
    // cout<<p<<endl;
    return 0;
}