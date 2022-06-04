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
    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<lli,lli> m;
    m.insert({0,1});
    vector<lli> prefix(n,0);
    prefix[0]= v[0];
    for(int i=1;i<n;i++){
        prefix[i]= prefix[i-1] + v[i];
    }
    lli totSubarrays=0;
    for(int i=0;i<n;i++){
        if(m.find(prefix[i]-x)!=m.end()){
            totSubarrays+= m[prefix[i]-x];
        }
        m[prefix[i]]++;
    }
    c(totSubarrays);
    return 0;
}