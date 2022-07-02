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

void recur(int o,int c,string temp,vector<string> &ans){
    if(o==0 && c==0){
        ans.push_back(temp);
        return ;
    }
    if(o>0){
        recur(o-1,c,temp+'(',ans);
    }
    
    if(c>0 && c>o){
        recur(o,c-1,temp+ ')',ans);
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    recur(n,n,"",ans);

    return ans;

}

int main(){
    
    return 0;
}