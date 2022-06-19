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

int numSplits(string s) {
    int n= s.size();
    vi prefix(26,0);
    vi suffix(26,0);
    int ctSuffix=0;
    int ctPrefix= 0;
    for(int i=0;i<n;i++){
        if(suffix[s[i]-'a']==0){
            ctSuffix++;
        }
        suffix[s[i]-'a']++;
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        int idx= s[i]-'a';
        suffix[idx]--;
        if(suffix[idx]==0){
            ctSuffix--;
        }
        if(prefix[idx]==0){
            ctPrefix++;
        }
        prefix[idx]++;
        if(ctPrefix== ctSuffix){
            ans++;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}