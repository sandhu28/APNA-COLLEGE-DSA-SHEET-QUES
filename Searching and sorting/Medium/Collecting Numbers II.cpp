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
    int n,m;cin>>n>>m;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int pos[n+1]= {};
    for(int i=0;i<n;i++){
        pos[v[i]] = i;
    }
    int ct=1;
    for(int i=2;i<=n;i++){
        if(pos[i]< pos[i-1]){
            ct++;
        }
    }
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x= x-1;y= y-1;
        int n1= v[x],n2= v[y];
        set<pii> s;
        if(n1==1){
            s.insert({n1,n1+1});
            s.insert({n2,n2+1});
            s.insert({n2-1,n2});
        }
        else if(n2==1){
            s.insert({n2,n2+1});
            s.insert({n1,n1+1});
            s.insert({n1-1,n1});
        }
        else{
            s.insert({n2-1,n2});
            s.insert({n2,n2+1});
            s.insert({n1,n1+1});
            s.insert({n1-1,n1});
        }
        for(auto & pr: s){
            if(pos[pr.first]>pos[pr.second]){
                ct--;
            }
        }
        swap(v[x],v[y]);
        swap(pos[n1],pos[n2]);
        for(auto &pr:s){
            if(pos[pr.first]>pos[pr.second]){
                ct++;
            }
        }
        c(ct);

    }
    return 0;
}