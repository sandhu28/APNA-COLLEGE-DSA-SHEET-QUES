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

bool myCompare(pair<pii,int>&pr1, pair<pii,int> &pr2){
    if(pr1.first.first==pr2.first.first){
        return pr1.first.second> pr2.first.second;
    }
    return pr1.first.first< pr2.first.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pii,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        v[i]={{a,b},i};
    }
    sort(v.begin(),v.end(),myCompare);
    vi contained(n,0);
    vi contains(n,0);
    int mx= INT_MIN;
    for(int i=0;i<n;i++){
        auto pr= v[i].first;
        auto idx= v[i].second;
        if(pr.second<= mx){
            contained[idx]=1;
        }
        mx= max(mx, pr.second);
    }
    int mn= INT_MAX;
    for(int j=n-1;j>=0;j--){
        auto pr= v[j].first;
        auto idx= v[j].second;
        if(pr.second>= mn){
            contains[idx]=1;
        }
        mn= min(mn,pr.second);
    }
    for(auto &e: contains){
        z(e);
    }
    nl;
    for(auto &e: contained){
        z(e);
    }

    return 0;
}