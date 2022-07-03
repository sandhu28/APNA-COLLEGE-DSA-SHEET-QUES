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

int maxEnvelopes(vector<vector<int>>& env) {
    sort(all(env),[](vi a,vi b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        else{
            return a[1]>b[1];
        }
    });
    int ans=0;
    vi v;
    for(int i=0;i<env.size();i++){
        int h= env[i][1];
        auto it= lower_bound(all(v),h);
        if(it!=v.end()){
            v[it-v.begin()] = h;
        }
        else{
            v.push_back(h);
        }
        ans=v.size();
    }
    return ans;
}


int main(){
    
    return 0;
}