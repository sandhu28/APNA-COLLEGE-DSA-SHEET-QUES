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

    fast_io;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        vi v(26,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[s[i]-'A']==0){
                ans+= 2;
                v[s[i]-'A']=1;
            }
            else{
                ans+=1;
            }
        }
        c(ans);
    }
    
    return 0;
}