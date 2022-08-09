#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e6+ 3;



int32_t main(){

    fast_io;
    int n;cin>>n;
    vi pre(1e6+2,0);
    fo(i,n){
        int x;cin>>x;
        pre[x]++;
    }
    vi mul(1e6+2,0);
    int ans=LLONG_MIN;
    for(int i=1;i<=1e6+2;i++){
        for(int j=i;j<=1e6+2;j+= i){
            if(pre[j]){
                mul[i]+= pre[j];
            }
        }
        // if(i==422){c(mul[i]);}
        if(mul[i]>=2){
            ans= i;
        }
    }
    c(ans);
    
    return 0;
}