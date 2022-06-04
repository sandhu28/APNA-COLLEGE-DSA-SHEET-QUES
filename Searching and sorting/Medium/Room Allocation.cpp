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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<pair<pii,int>> v(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v[i]={{x,y},i};
    }
    sort(v.begin(),v.end());
    // c("yes");
    // for(auto &pr: v){
    //     z(pr.first.first);z(pr.first.second);
    //     c(pr.second);
    // }
    // c("yes");
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int roomNo= 1;
    vector<int> ans(n);
    for(auto &pPr: v){
        auto pr= pPr.first;
        int idx= pPr.second;
        int currRoomNo=0;
        if(pq.empty()){
            pq.push({pr.second,roomNo});
            currRoomNo= roomNo;
        }
        else{
            auto smallestLeavingTime = pq.top();
            int leavingTime= smallestLeavingTime.first;
            int roomToCheck= smallestLeavingTime.second;
            if(pr.first>leavingTime){
                pq.pop();
                pq.push({pr.second,roomToCheck});
                currRoomNo= roomToCheck;
            }
            else{
                roomNo++;
                pq.push({pr.second,roomNo});
                currRoomNo= roomNo;
            }
        }
        ans[idx]=(currRoomNo);
    }
    c(roomNo);
    for(auto &e: ans){
        z(e);
    }
    
    return 0;
}