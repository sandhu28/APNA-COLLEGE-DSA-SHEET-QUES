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

const int M=1e9 + 7;


int main(){
    int n,m;
    cin>>n>>m;
    vvi v(n+1);
    vi inDegree(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        inDegree[y]++;
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int ver= q.front();
        q.pop();
        for(auto &child: v[ver]){
            if(child==1){
                --inDegree[1];
                continue;
            }
            if((--inDegree[child])  == 0){
                q.push(child);
            }
        }
    }
    q.push(1);
    vi cnt(n+1,0);
    cnt[1]= 1;
    while(!q.empty()){
        int ver= q.front();
        q.pop();
        for(auto &child: v[ver]){
            --inDegree[child];
            cnt[child] = ((cnt[child]%M) + (cnt[ver]%M))%M;
            if(inDegree[child]==0){
                q.push(child);
            }
        }
    }

    c(cnt[n]);

    return 0;
}