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

int dfs(int i,int n,vlli &sz,vvi &tree){
    lli pro=1;int sm=1;
    for(auto &child: tree[i]){
        int cnt= dfs(child,n,sz,tree);
        pro *= cnt;
        sm+= cnt;
    }
    sz[i] = pro*(max(1LL, (long long)(n- sm -1)));
    return i!=0? sm: count(all(sz),*max_element(all(sz)));
}

int countHighestScoreNodes(vector<int>& p) {
    int n= p.size();
    vvi tree(n);
    vlli sz(n);
    for(int i=1;i<n;i++){
        tree[p[i]].push_back(i);
    }
    return dfs(0,n,sz,tree);
}

int main(){
    
    return 0;
}


