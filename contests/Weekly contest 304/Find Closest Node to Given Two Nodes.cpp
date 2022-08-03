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

void dfs(vi &dis, vi &g,int i,int cd,vi &vis){
    if(vis[i]){return;}
    dis[i]= cd;
    if(g[i]!=-1){
        dfs(dis,g,g[i],cd+1,vis);
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {

    int n= edges.size();  
    vi vis(n,0);
    vi dis1(n,1e8);
    dfs(dis1,edges,node1,0,vis);
    fo(i,n){vis[i]=0;}
    vi dis2(n,1e8);
    dfs(dis2,edges,node2,0,vis);
    int ans= INT_MAX;
    int node=-1;
    fo(i,n){
        int curr= max(dis1[i],dis2[i]);
        if(curr<ans){
            ans= curr;
            node= i;
        }
    }
    if(ans== 1e8){
        return -1;
    }
    return node;


}

int main(){
    
    return 0;
}