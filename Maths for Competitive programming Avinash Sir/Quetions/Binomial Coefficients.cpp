#include<iostream>
#include<bits/stdc++.h>
#define int long long int
#define pii pair<int,int>
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ff first
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<' '
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e6+ 1;
vi fact(N,1);
vi invf(N,1);

void calcFact(){
    fact[1]=1;
    for(int i=2;i<=1e6;i++){
        fact[i]= (fact[i-1]*i)%M;
    }
}

int a_to_b(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1){
            ans= (ans*a)%M;
        }
        b>>=1;
        a= (a*a)%M;
    }
    return ans;
}

int invFact(int k){
    return a_to_b(k,M-2);// fermat theorem
}

int32_t main(){
    fast_io;
    int n;cin>>n;
    calcFact();

    while(n--){
        int a,b;
        cin>>a>>b;
        int a_fac= fact[a];
        int b_fac= fact[b];
        int amb_fac= fact[a-b];
        int k= (fact[b]*fact[a-b])%M;
        int inv= invFact(k);
        int ans= (a_fac*inv)%M;
        c(ans);
    }
    
    return 0;
}