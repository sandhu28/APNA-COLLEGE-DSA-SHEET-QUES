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

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int main(){

    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    vi ans;
    ans.push_back(v[0]);
    int L= 1;
    for(int i=1;i<n;i++){
        auto it= lower_bound(ans.begin(),ans.end(),v[i]);
        if(it== ans.end()){
            ans.push_back(v[i]);
        }
        else{
            ans[it-ans.begin()] = v[i];
        }
        int sz = ans.size();
        L= max(L,sz);
    }
    c(L);

    
    return 0;
}