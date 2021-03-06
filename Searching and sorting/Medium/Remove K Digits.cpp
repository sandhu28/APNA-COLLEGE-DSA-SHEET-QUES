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

string removeKdigits(string num, int k) {
    int n= num.size();
    stack<char> stk;
    if(k==0){
        return num;
    }
    for(auto &ch: num){
        while((!stk.empty()) && (k>0) && (ch< stk.top())){
            k--;
            stk.pop();
        }
        if((!stk.empty()) || (ch!='0')){
            stk.push(ch);
        }
    }
    while(k>0){
        k--;
        stk.pop();
    }
    if(stk.empty()){
        return "0";
    }
    string ans="";
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(all(ans));
    return ans;

}

int main(){
    
    return 0;
}