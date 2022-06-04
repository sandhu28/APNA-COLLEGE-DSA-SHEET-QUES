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
    int x,n;cin>>x>>n;
    // vector<int> v(n);
    multiset<int> ms;
    set<int> s;
    s.insert(0);s.insert(x);ms.insert(x-0);
    for(int i=0;i<n;i++){
        int k;cin>>k;
        s.insert(k);
        auto it = s.find(k);
        int pr= *prev(it);
        int nx= *next(it);
        ms.erase(ms.find(nx-pr));
        ms.insert(k-pr);
        ms.insert(nx-k);
        z(*ms.rbegin());
    }

    return 0;
}