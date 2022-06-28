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
const int N = 1e5;

lli a_to_b(int temp,int b){
    lli ans=1;
    lli a= temp;
    while(b>0){
        if(b&1){
            ans = (ans*1LL*a);
        }
        a= a*a;
        b>>= 1;
    }
    return ans;
}

int main(){
    fast_io;
    // int t;cin>>t;
    // while(t--){
        int n;cin>>n;
        int q;cin>>q;
        vi v(n);
        for(int i=0;i<n;i++){
            // int x;cin>>x;
            cin>>v[i];
        }
        sort(all(v));
        while(q--){
            int x;cin>>x;
            auto prv= lower_bound(all(v),x);
            if(*prv==x){
                c('0');
            }
            else{
                if(prv== v.end()){
                    c('1');                   
                }
                else{
                    auto check= v.end() - (prv) ;
                    if(check&1){
                        c("-1");
                    }
                    else{
                        c("1");
                    }
                }
                
            }
        }
    // }
    
    return 0;
}