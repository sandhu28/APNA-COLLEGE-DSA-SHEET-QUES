#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


int binarySearch(vi& v,int mxPrice, vi& vis){
    int n= v.size();
    int l=0;int h= n-1;
    int pos=-1;
    while(l<=h){
        int mid= l + (h-l)/2;
        if(vis[mid]==1){
            if(v[h]>mxPrice){
                h= h-1;
            }
            else{
                l= l+1;
            }
            continue;
        }
        if(v[mid]<= mxPrice){
            pos= mid;
            l= mid+1;
        }
        else{
            h= mid-1;
        }
    }
    return pos;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    set<pii> s;
    vi maxPriceByCustomer(m);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.insert({x,i});
    }
    for(int i=0;i<m;i++){
        cin>>maxPriceByCustomer[i];
    }
    for(int i=0;i<m;i++){
        int curr= maxPriceByCustomer[i];
        auto it= s.lower_bound({curr+1,0});
        if(it==s.begin()){
            cout<<"-1"<<endl;
        }
        else{
            it--;
            cout<<(*it).first<<endl;
            s.erase(it);
        }
        
    }
    return 0;
}