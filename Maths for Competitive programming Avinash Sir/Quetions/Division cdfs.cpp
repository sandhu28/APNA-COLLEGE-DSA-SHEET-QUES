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
const int N = 50000;

vi prime_fact(){
    vector<bool> isPrime(N+2,1);
    isPrime[1]=0;
    vi pf;
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=i){
                isPrime[j]=0;
            }
        }    
    }
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            pf.push_back(i);
        }
    }
    return pf;
}

vi pf_q(int q,vi &pf){
    vi q_pf;
    for(int i=0;i<pf.size();i++){
        if(pf[i]*pf[i]>q){
            break;
        }
        if(q%pf[i]==0){
            q_pf.push_back(pf[i]);
            while(q%pf[i]==0){
                q= q/pf[i];
            }
        }
        
    }
    if(q>1){
        q_pf.push_back(q);
    }
    return q_pf;
}

int32_t main(){
    fast_io;
    int t;cin>>t;
    vi pf= prime_fact();
    while(t--){
        int p,q;
        cin>>p>>q;
        if(p%q!=0){
            c(p);
            continue;
        }
        vi qPf= pf_q(q,pf);
        // for(auto y:qPf){
        //     c(y);
        // }
        int ans= 0;
        for(int &prime: qPf){
            int x= p;
            while(x%q==0){
                x= x/prime;
            }
            ans= max(ans,x);
        }
        c(ans);
    }    
    return 0;
}