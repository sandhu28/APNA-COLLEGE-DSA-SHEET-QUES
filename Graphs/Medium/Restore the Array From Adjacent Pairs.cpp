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

void dfs(map<int,vi> &m,vi &ans,int node,int par){
    ans.push_back(node);
    for(auto &child: m[node]){
        if(par==child){continue;}
        dfs(m,ans,child,node);
    }
}

vector<int> restoreArray(vector<vector<int>>& prs) {

    map<int,vi> m;
    int n= prs.size();
    for(int i=0;i<n;i++){
        int a= prs[i][0];
        int b= prs[i][1];
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int st;
    for(auto &it: m){
        if(it.second.size()==1){
            st= it.first;
            break;
        }
    }
    vi ans;
    dfs(m,ans,st,1e5+2);
    return ans;

        
}


int main(){
    
    return 0;
}