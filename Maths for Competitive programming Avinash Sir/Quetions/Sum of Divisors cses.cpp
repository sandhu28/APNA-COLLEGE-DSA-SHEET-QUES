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
const int N = 1e5+ 3;

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

int sm(int l,int h,int inv){
    int a=  ((h%M)*((h+1)%M))%M;         
    a= (a*inv)%M;
    int b= ((l%M)*((l+1)%M))%M; 
    b= (b*inv)%M;
    return (a-b+M)%M;
}

int32_t main(){
    
    fast_io;
    int n;cin>>n;
    int inv= a_to_b(2,M-2);
    // c(inv);
    int i=1;
    int ans=0;
    while(i<=n){
        int contri= n/i;
        int iDash= (n/contri)+1;
        int temp= (sm(i-1,iDash-1,inv))%M;
        ans= (ans%M + (((contri%M)*temp)%M))%M;
        i= iDash;
    }
    c(ans);

    return 0;
}