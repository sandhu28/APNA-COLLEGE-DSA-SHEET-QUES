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

// int recur(string &s,int k,string curr,int i){
//     if(i==s.size()){
//         return curr.size();
//     }
//     int ans= INT_MIN;
//     ans= recur(s,k,curr,i+1);
//     curr+= s[i];
//     int num= stoi(curr);
//     if(num<k){
//         ans= max(ans,1+ recur(s,k,curr,i+1));
//     }
//     return ans;
// }
int longestSubsequence(string s, int k) {
    int ct =0;
    for(auto &ch : s){
        if(ch=='0'){
            ct++;
        }
    }
    int sm=0;int pow=1;int l=0;
    for(int i=s.size()-1;i>=0 && (pow + sm<=k);i--){
        if(s[i]=='0'){ct--;}
        sm += (s[i] - '0')*pow;
        pow <<= 1;
        l++;
    }
    return ct+ l;

}


int main(){
    
    return 0;
}