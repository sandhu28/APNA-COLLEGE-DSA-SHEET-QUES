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
    c(ct);

    return 0;
}