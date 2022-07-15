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
    int t;cin>>t;
    vlli pw2(33,1);
    for(int i=0;i<33;i++){
        pw2[i]= 1LL*(1<<i);
    }

    while(t--){
        int n;cin>>n;
        int k;cin>>k;
        vi v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        vlli pre(n);
        pre[0]= v[0];
        rep(i,1,n){
            pre[i]= pre[i-1]+ 1LL*v[i];
        }
        lli ans=LLONG_MIN;
        for(int i=-1;i<n;i++){
            lli curr=0;
            if(i!=-1){
                curr= pre[i]*1LL-(k*1LL*(i+1));
            }
            // c(curr);
            // lli cur=0;
            for(int j=i+1;(j<i+32) && (j<n);j++){
                curr+=  (1LL*v[j])/(pw2[j-i]);
                // z(two);
            }
            // nl;
            ans= max(curr,ans);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}