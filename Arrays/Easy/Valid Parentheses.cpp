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

// Using stacks.
bool isValid(string s) {
        stack<char> stk;
        int n= s.size();
        // if(n==1){return false;}
        unordered_map<char,char> um={{'[',']'},{'{','}'},{'(',')'}};
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]== '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                char ch= stk.top();
                stk.pop();
                if(s[i]!= um[ch]){return false;}
            }
        }
        return stk.empty();
}


int main(){
    
    return 0;
}