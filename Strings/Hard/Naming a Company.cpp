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

long long distinctNames(vector<string>& ideas) {
    int n= ideas.size();
    map<int,set<string>> m;
    for(int i=0;i<n;i++){
        m[(ideas[i][0] - 'a')].insert(ideas[i].substr(1));
    }  
    long long ans=0;
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            int ct=0;
            for(auto &str: m[i]){
                if(m[j].count(str)){
                    ct++;
                }
            }
            ans += 2*((m[i].size()-ct) * (m[j].size()-ct));

        }
    }
    return ans;
}

int main(){
    
    return 0;
}