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
#define vs vector<string>
#define ss second
#define ff first
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

int longestSubstring(string s, int k) {

    int n= s.size();
    int ans= INT_MIN;
    for(int uniq= 1;uniq<=26;uniq++){
        vi ct(26,0);
        int i=0,j=0;
        int uqTillNow=0;int ctK=0;
        while(j<n){
            if(uqTillNow<= uniq){
                if(ct[s[j]-'a']==0){
                    uqTillNow++;
                }
                ct[s[j]-'a']++;
                if(ct[s[j]-'a']==k){
                    ctK++;
                }
            }
            else{
                if(ct[s[i]-'a']==k){
                    ctK--;
                }
                ct[s[i]-'a']--;
                if(ct[s[i]-'a']==0){
                    uqTillNow--;
                }
            }
            if(uqTillNow== uniq && ctK== uniq){
                ans= max(ans,j-i);
            }
        }
    }
    return ans;

}

int main(){
    
    return 0;
}