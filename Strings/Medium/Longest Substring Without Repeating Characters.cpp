#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n= s.size();
    int st=0;int en=0;
    unordered_map<int,int> um;
    int mx= INT_MIN;
    while(st<=en && en<n){
        if(um.find((s[en]-'a'))!= um.end() && um[s[en]-'a']>=st){
            st = um[s[en]-'a'] + 1;
            um[s[en]-'a'] = en;
            en++;
        }
        else{
            um[s[en]-'a'] = en;
            en++;
            mx= max(mx,en- st);
        }
    }  
    return mx;
}
int main(){
    
    return 0;
}