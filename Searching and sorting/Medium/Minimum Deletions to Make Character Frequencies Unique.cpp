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

int minDeletions(string s) {
    int n= s.size();
    vi freq(26,0);
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }       
    set<int> st;
    int ans=0;
    for(int i=0;i<26;i++){
        if(freq[i]){
            if(st.find(freq[i])!=st.end()){
                freq[i]--;
                ans++;
                while(st.find(freq[i])!=st.end()){
                    freq[i]--;
                    ans++;
                }
                if(freq[i]){
                    st.insert(freq[i]);
                }
            }
            else{
                st.insert(freq[i]);
            }
        }
    }
    return ans;
}


int main(){
    
    return 0;
}