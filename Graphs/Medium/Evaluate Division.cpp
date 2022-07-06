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

double dfs(double ans, string a,string b,unordered_map<string,vector<pair<string,double>>> &m,unordered_map<string,bool> &vis){

    if(a==b){
        return ans;
    }
    vis[a]= 1;
    for(auto &pr: m[a]){
        string child= pr.first;
        double val= pr.second;
        if(vis.find(child)!=vis.end()){
            continue;
        }
        double ret= dfs(ans*val,child,b,m,vis);
        if(ret!=-1.0){
            return ret;
        }
    }
    return -1.0;
    
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
    vector<double> ans;
    unordered_map<string,vector<pair<string,double>>> m;
    int n= equations.size();
    for(int i=0;i<n;i++){
        auto vec= equations[i];
        string a= vec[0];
        string b= vec[1];
        m[a].push_back({b,values[i]});
        m[b].push_back({a,1/(1.0*values[i])});
    }
    int q = queries.size();
    for(int i=0;i<q;i++){
        auto vec= queries[i];
        string a= vec[0];
        string b= vec[1];
        if((m.find(a)==m.end() || m.find(b)==m.end())){
            ans.push_back(-1.0);
            continue;
        }  
        else if(a==b){
            ans.push_back(1.0);
            continue;
        }
        unordered_map<string,bool> vis;
        double ret= dfs(1.0,a,b,m,vis);
        ans.push_back(ret);
    }
    return ans;
}


int main(){
    
    return 0;
}