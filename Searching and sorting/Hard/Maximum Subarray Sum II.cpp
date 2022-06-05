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
    int n, a,b;
    cin >> n >> a>>b;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vlli prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]= prefix[i] + 1LL*v[i];
    }
    set<pair<lli,int>> s;
    for(int i=a;i<=b;i++){
        s.insert({prefix[i],i});
    }
    lli mx= LLONG_MIN;
    for(int i=1;i<=n-a+1;i++){
        auto pr= *s.rbegin();
        mx= max(mx, pr.first - prefix[i-1]);
        auto it= s.find({prefix[i+a-1],i+a-1});
        s.erase(it);
        if(i+b<=n){
            s.insert({prefix[i+b],i+b});
        }
    }
    c(mx);
    return 0;
}