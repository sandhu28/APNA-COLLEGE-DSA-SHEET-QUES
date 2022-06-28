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

// int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
//     vi indeg(n+1,0);
//     vvi g(n+1);
//     for(auto &pr: relations){
//         g[pr[0]].push_back(pr[1]);
//         indeg[pr[1]]++;
//     }
//     vi sem(n+1,0);
//     vi mx_tm(n+1,0);
//     // map<int,int> m;
//     queue<pii> q; //node,lev
//     int give_sem=1;
//     for(int i=1;i<=n;i++){
//         if(indeg[i]==0){
//             // if(m.find(give_sem)!=m.end() ){
//             //     if(m[give_sem]>=k){
//             //         give_sem++;
//             //     }
//             // }
//             q.push({i,give_sem});
//             sem[i] = give_sem;
//             mx_tm[give_sem] = max(mx_tm[give_sem],time[i]);
//         }
//     }
//     // int ans= INT_MAX;
//     while(!q.empty()){
//         auto pr= q.front();
//         q.pop();
//         // ans= max(ans,pr.second);
//         for(auto &child: g[pr.first]){
//             indeg[child]--;
//             sem[child] = max(sem[child],1+pr.second);
            
//             if(indeg[child]==0){
//                 q.push({child,sem[child]});
//                 mx_tm[sem[child]]= max(mx_tm[sem[child]], time[child]);
//             }
//         }
//     }
//     return accumulate(all(mx_tm),0);
// }

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vi indeg(n+1,0);
    vvi g(n+1);
    for(auto &pr: relations){
        g[pr[0]].push_back(pr[1]);
        indeg[pr[1]]++;
    }
    vi dist(n+1,0);
    queue<pii> q; //node,dist
    int give_sem=0;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push({i,give_sem});
            dist[i] = time[i-1];
        }
    }
    // int ans= INT_MAX;
    while(!q.empty()){
        auto pr= q.front();
        q.pop();
        int u= pr.first,d= pr.second;
        // ans= max(ans,pr.second);
        for(auto &v: g[pr.first]){
            indeg[v]--;
            dist[v] = max(dist[v],d + time[v-1]);
            if(indeg[v]==0){
                q.push({v,dist[v]});
                // mx_tm[sem[child]]= max(mx_tm[sem[child]], time[child]);
            }
        }
    }
    return *max_element(all(dist));
}
int main(){
    
    return 0;
}