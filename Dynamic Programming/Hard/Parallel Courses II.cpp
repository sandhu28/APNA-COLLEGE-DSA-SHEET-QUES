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



// int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
//     vi indeg(n+1,0);
//     vvi g(n+1);
//     for(auto &pr: relations){
//         g[pr[0]].push_back(pr[1]);
//         indeg[pr[1]]++;
//     }
//     vi sem(n+1,0);
//     map<int,int> m;
//     queue<pii> q; //node,lev
//     int give_sem=1;
//     for(int i=1;i<=n;i++){
//         if(indeg[i]==0){
//             if(m.find(give_sem)!=m.end() ){
//                 if(m[give_sem]>=k){
//                     give_sem++;
//                 }
//             }
//             q.push({i,give_sem});
//             sem[i] = give_sem;
//         }
//     }
//     int ans= INT_MAX;
//     while(!q.empty()){
//         auto pr= q.front();
//         q.pop();
//         ans= max(ans,pr.second);
//         for(auto &child: g[pr.first]){
//             indeg[child]--;
//             sem[child] = max(sem[child],1+pr.second);
//             if(indeg[child]==0){
//                 q.push({child,sem[child]});
//             }
//         }
//     }
//     return *max_element(all(sem));
// }

int n,k;
vector<int> g[15];
vector<int> dp;

int req_sems(int mask){
    if(mask== (1<<n)-1){
        return 0;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }

    vi indeg(n,0);
    // indeg[i] =no of prerequi for ith course
    // excluding the course already taken
    for(int i=0;i<n;i++){
        if(mask & (1<<i)){
            continue;
        }
        else{
            for(int j=0;j<g[i].size();j++){
                indeg[g[i][j]]++;
            }
        }
    } 

    int avail_mask = 0;
    // The mask of course available.
    for(int i=0;i<n;i++){
        if(indeg[i]==0 && !(mask &(1<<i))){
            avail_mask |= (1<<i);
        }
    }

    int num_avail =__builtin_popcount(avail_mask);
    int taken= n+1;
    // The max course taken at any pt is n.-> n+1=INF.
    if(num_avail> k){
        /// Enumerate all submasks
        int m= num_avail;
        int s;
        for(s=m; s; s= (s-1)&m){
            if(__builtin_popcount(s) !=k){
                continue;
            }
            taken = min(taken, 1+ req_sems(mask|s));
        }
    }
    else{
        // its wise to take all the available course.
        taken = min(taken,1+req_sems(mask|avail_mask));
    }
    return dp[mask] = taken;

}

// int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
//     n= N;
//     k= K;
//     dp.assign(1<<n,-1);
//     for(int i=0;i<relations.size();i++){
//         relations[i][0]--;
//         relations[i][1]--;
//         g[relations[i][0]].push_back(relations[i][1]);
//     }
//     int ans = req_sems(0);
//     // 0 means course is not completed
//     // 1 means course is completed
//     // sems req to complete courses given the current state.
//     return ans;
    

// }

int main(){
    
    return 0;
}