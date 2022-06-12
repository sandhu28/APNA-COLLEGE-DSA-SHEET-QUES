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

// I tried to store parents along with weights in this problem but that's incorrect bz the shortest path using normal djikstra need be the shortest path after using coupon. eg; two path 100,100 and 10,200 here 100,100 is shortest but after coupon ans is 150 and in other case after coupon ans is 110. 
void djikstra(vector<vpii> v,int n,vlli &dis,vi &vis,vpii &par){
    set<pair<lli,int>> s;// dist, vertex
    s.insert({0,1});
    dis[1] =0;
    while(!s.empty()){
        auto pr= *s.begin();
        s.erase(s.begin());
        int currVer= pr.second;
        if(vis[currVer]==1){continue;}
        for(auto &child: v[currVer]){
            int childVer= child.first;
            int w = child.second;
            if(dis[currVer] + 1LL*w < dis[childVer]){
                dis[childVer] = dis[currVer] + 1LL*w;
                par[childVer] = {currVer,w};
                s.insert({dis[childVer],childVer});
            }
        }
        vis[currVer] =1;
    }
}

void djikstra_1(vector<vpii> v,int n,vlli &couponUsed, vlli &couponNotUsed){
    set<pair<pair<lli,int>,bool>> s;// dist, vertex
    s.insert({{0,1},0});
    couponUsed[1] =0;
    couponNotUsed[1] = 0;
    while(!s.empty()){
        auto pr= *s.begin();
        s.erase(s.begin());
        int currVer= pr.first.second;
        bool flag= pr.second;
        lli currCost= pr.first.first;
        // if(vis[currVer]==1){continue;}
        for(auto &child: v[currVer]){
            int childVer= child.first;
            int w = child.second;
            if(flag){
                if(currCost + 1LL*w < couponUsed[childVer]){
                    couponUsed[childVer] = currCost + 1LL*w;
                    s.insert({{couponUsed[childVer],childVer},1});
                }
            }
            else{
                if(currCost + 1LL*(w/2) < couponUsed[childVer]){
                    couponUsed[childVer] = currCost + 1LL*(w/2);
                    s.insert({{couponUsed[childVer],childVer},1});
                }
                if(currCost + 1LL*w < couponNotUsed[childVer]){
                    couponNotUsed[childVer] = currCost + 1LL*(w);
                    s.insert({{couponNotUsed[childVer],childVer},0});
                }
            }
        }
        // vis[currVer] =1;
    }
}
int main(){
    int n,m;cin>>n>>m;
    vlli couponUsed(n+1,LONG_MAX);
    vlli couponNotUsed(n+1,LONG_MAX);
    // vi vis(n+1, 0);
    // vpii par(n+1,{-1,-1});
    vector<vpii> v(n+1);
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        v[x].push_back({y,w});
        // v[y].push_back({x,w});
    }
    djikstra_1(v,n,couponNotUsed,couponUsed);
    c(couponNotUsed[n]);

    return 0;
}