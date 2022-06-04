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
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    multiset<int> ms;
    for(int i=0;i<n;i++){
        if(ms.empty()){
            ms.insert(v[i]);
        }
        else if(ms.upper_bound(v[i])!=ms.end()){
            auto it= ms.upper_bound(v[i]);
            ms.erase(it);
            ms.insert(v[i]);
        }
        else{
            ms.insert(v[i]);
        }
    }
    c(ms.size());

    return 0;
}