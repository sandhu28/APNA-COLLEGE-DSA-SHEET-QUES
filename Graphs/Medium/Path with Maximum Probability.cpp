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

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<pair<int,double>> g[n];
    for(int i=0;i<edges.size();i++){
        auto pr= edges[i];
        g[pr[0]].push_back({pr[1],succProb[i]});
        g[pr[1]].push_back({pr[0],succProb[i]});
    }
    set<pair<double,int>> st;
    vector<double> dist(n,-1);
    vector<bool> vis(n,0);
    st.insert({1.0,start});
    dist[start]= 1.0;
    while(!st.empty()){
        auto pr= *(--st.end());
        st.erase(--st.end());
        if(vis[pr.second]==1){
            continue;
        }
        for(auto & child: g[pr.second]){
            if((vis[child.first] ==0) && ((dist[pr.second]*child.second) > dist[child.first])){
                dist[child.first]= (dist[pr.second]*child.second);
                st.insert({dist[child.first],child.first});
            }
        }
        vis[pr.second] = 1;
    }
    return dist[end]==-1? 0.0000: dist[end];

}

int main(){
    
    return 0;
}