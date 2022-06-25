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

// int par[N];
// int sz[N];

void make(int n,vi &sz,vi &par){
    par[n]=n;
    sz[n] = 1;
}

int find(int n,vi &par){
    
    if(par[n]==n){
        return n;
    }
    return par[n]  = find(par[n],par);
}

void Union(int a,int b,vi &sz,vi &par){
    a= find(a,par);
    b= find(b,par);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        par[b]= a;
        sz[a]+= sz[b];
    }
}

long long countPairs(int n, vector<vector<int>>& edges) {
    //  c("yes");
    vi par(n,-1);
    vi sz(n,0);
    for(int i=0;i<n;i++){
        make(i,sz,par);
    }
    for(auto &pr: edges){
        Union(pr[0],pr[1],sz,par);
    }
    // map<int,int> m;// par,size
    vi v;
    for(int i=0;i<n;i++){
        if(par[i]==i){
            v.push_back(sz[i]);
        }
    }
   
    int m= v.size();
    lli ans=0;
    
    vlli suffix(m,0);
    for(int i=m-2;i>=0;i--){
        suffix[i]= suffix[i+1]+ 1LL*v[i+1];
    }
    for(int i=0;i<m-1;i++){
        ans+= v[i]*1LL*(suffix[i]);
    }
    return ans;
}


int main(){
    int n;cin>>n;
    int m;cin>>m;
    vvi edges;
    for(int i=0;i<m;i++){
        vi temp;
        int x,y;cin>>x>>y;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
    }
    c(countPairs(n,edges));
    
    
    return 0;
}