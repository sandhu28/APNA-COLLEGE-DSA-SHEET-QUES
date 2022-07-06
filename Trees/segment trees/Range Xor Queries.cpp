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

int main(){

    int n;cin>>n;
    int q;cin>>q;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    vi prefix(n,0);
    prefix[0]= v[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]^v[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==1){
            c(prefix[b-1]);
            continue;
        }
        cout<<(prefix[b-1]^prefix[a-2]);
        cout<<endl;
    }
    
    return 0;
}