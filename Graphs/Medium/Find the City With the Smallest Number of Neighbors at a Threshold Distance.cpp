#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
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

int findTheCity(int n, vector<vector<int>>& edges, int d) {
    vvi g(n,vi(n,1e8));
    fo(i,edges.size()){
        int a= edges[i][0],b= edges[i][1],w= edges[i][2];
        g[a][a]= g[b][b]=0;
        g[a][b]= w;
    }
    for(int k=0;k<n;k++){
        fo(i,n){
            fo(j,n){
                g[i][j]= min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    int ans=-1;
    int mn_ct=INT_MAX;
    fo(i,n){
        int ct=0;
        fo(j,n){
            if(g[i][j]<= d && i!=j){
                ct++;
            }
        }
        if(ct<=mn_ct){
            ans= i;
        }
    }
    return ans;

}

int main(){
    
    return 0;
}