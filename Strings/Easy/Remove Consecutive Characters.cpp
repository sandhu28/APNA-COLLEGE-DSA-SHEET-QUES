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

string removeConsecutiveCharacter(string s)
{
    char prev= s[0];
    string ans="";
    ans+=prev;
    int n= s.size();
    for(int i=1;i<n;i++){
        if(s[i]== prev){
            continue;
        }
        ans+= s[i];
        prev= s[i];
    }
    return ans;
}
int main(){
    
    return 0;
}