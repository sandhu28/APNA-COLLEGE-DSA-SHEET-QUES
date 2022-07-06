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

int find(int i,vi &par){
    if(par[i]==i){
        return i;
    }
    return par[i]  = find(par[i],par);
}

void Union(int a,int b,vi &par,vi &sz){
    a= find(a,par);
    b= find(b,par);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        par[b]=a;
        sz[a]+= sz[b];
    }
}

bool equationsPossible(vector<string>& eq) {
    int n= eq.size();
    vi par(26,-1);
    vi sz(26,0);
    for(int i=0;i<26;i++){
        par[i]=i;
        sz[i]=1;
    }

    for(int i=0;i<n;i++){
        int a= eq[i][0]-'a';
        int b= eq[i][3]-'a';
        if(eq[i][2]=='!'){
            if(a==b){return 0;}
            if(find(a,par)==find(b,par)){
                return 0;
            }
        }
        else{
            Union(a,b,par,sz);
        }
    }
    return 1;

}


int main(){
    
    return 0;
}