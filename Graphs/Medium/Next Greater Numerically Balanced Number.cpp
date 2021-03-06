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

int dfs(int n,int val,vi &ct,int sz){
    if(sz==0){
        for(int i=1;i<=9;i++){
            if((ct[i]!=i)  && (ct[i]!=0)){
                return 0;
            }
        }
        return val>n? val: 0;
    }
    int res=0;
    for(int i=1;(res>0) && i<=9;i++){
        if(ct[i]>0 && ct[i]<= sz){
            --ct[i];
            res= dfs(n,val*10 + i,ct,sz-1);
            ++ct[i];
        }
    }
    return res;
}

int nextBeautifulNumber(int n) {
    vi ct(10,0);
    for(int i=0;i<=9;i++){
        ct[i] =i;
    }
    string s= to_string(n);
    int sz= s.size();
    return dfs(n,0,ct,sz)?: dfs(n,0,ct,sz);

}

int main(){
    
    return 0;
}