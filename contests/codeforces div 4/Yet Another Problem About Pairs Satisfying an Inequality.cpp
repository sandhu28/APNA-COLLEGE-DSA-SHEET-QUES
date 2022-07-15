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
    while(t--){
        int n;cin>>n;
        vi st;
        vi v(n);
        rep(i,0,n){
            cin>>v[i];
            if(i+1> v[i]){
                st.push_back(i+1);
            }
        }
        lli ans=0;
        for(auto &it: st){
            int aj= v[it-1];
            auto iter= lower_bound(all(st),aj);
            if(iter== st.begin()){
                continue;
            }
            iter--;
            int ct= iter- st.begin()+1;
            ans = ans + 1LL*ct;
        }
        c(ans);

    }
    
    return 0;
}