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

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

    queue<pair<int,bool>> q;
    q.push({0,0});
    unordered_set<int> fbd;
    vvi vis(2,vi(1e6+2));
    vis[0][0]=vis[1][0]= 1;
    int level=0;
    fo(i,forbidden.size()){
        fbd.insert(forbidden[i]);
    }
    while(!q.empty()){
        int sz= q.size();
        while(sz--){
            int cN= q.front().first;
            bool back= q.front().second;
            q.pop();

            if(cN== x){
                return level;
            }

            int next= cN+ a;
            if(next<= 1e6 && vis[0][next]==0 && !fbd.count(next)){
                vis[0][next]=1;
                q.push({next,0});
            }

            int prev= cN- b;
            if(prev>=0 && back==0 && vis[1][prev]==0 && !fbd.count(prev)){
                vis[1][prev]=1;
                q.push({prev,1});
            }

        }
        level++;
    }
    return -1;

}

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

    queue<pair<int,bool>> q;
    q.push({0,0});
    unordered_set<int> fbd;
    // unordered_set<int> vis;
    // vis.insert(0);
    vi lev(1e6+2,INF);
    // int level=0;
    lev[0]=0;
    fo(i,forbidden.size()){
        fbd.insert(forbidden[i]);
    }
    while(!q.empty()){
        int sz= q.size();
        while(sz--){
            int cN= q.front().first;
            bool back= q.front().second;
            q.pop();

            if(cN== x){
                return lev[x];
            }

            int next= cN+ a;
            if(next<= 1e6 && (lev[next]>lev[cN]+1) && !fbd.count(next)){
                // vis.insert(next);
                lev[next]= lev[cN] + 1;
                q.push({next,back});
            }

            int prev= cN- b;
            if(prev>=0 && back==0 && lev[prev]>lev[cN] + 1 && !fbd.count(prev)){
                lev[prev]= lev[cN] + 1;
                q.push({prev,1});
            }

        }
    }
    return -1;

}

int main(){
    
    return 0;
}