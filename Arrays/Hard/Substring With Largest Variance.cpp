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

int largestVariance(string s) {
    int n= s.size();
    unordered_set<char> us(all(s));
    int ans=INT_MIN;
    for(auto &a: us){
        for(auto &b: us){
            int var=0,has_b=0,first_b=0;
            for(auto &ch: s){
                var += (ch==a);
                if(ch==b){
                    has_b=1;
                    if(first_b && (var>0)){
                        first_b=0;
                    }
                    else{
                        if(--var<0){
                            first_b= 1;
                            var= -1;
                        }
                    }
                }
                ans= max(ans,has_b?var:0);
            }
        }
    }
    return ans;
}


int main(){


    
    return 0;
}