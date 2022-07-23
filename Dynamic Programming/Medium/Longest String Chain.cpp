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

bool comp(string &a,string &b){
    int n= a.size();
    int m= b.size();
    int i=0,j=0;int ct=0;
    while(i<n && j<m){
        if(a[i]!=b[j]){
            i++;
            ct++;
        }
        else{
            i++;
            j++;
        }
    }
    if(j<m){return 0;}
    while(i<n){
        ct++;
    }
    return ct==1;
}

int longestStrChain(vector<string>& words) {
    int n= words.size();
    sort(all(words),[](string &a,string &b){
        return a.size()<=b.size();
    });
    vi dp(n,1);
    int ans= 1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(comp(words[i],words[j])){
                dp[i]= max(dp[i],dp[j]+1);
            }
        }
        ans= max(ans,dp[i]);
    }
    return ans;
}

int main(){
    
    return 0;
}