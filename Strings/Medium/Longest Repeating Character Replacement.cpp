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

int characterReplacement(string s, int k) {
    int arr[26]={};
    int n= s.size();
    int st=0,en=1;
    int mx_ct=1,mx_l= 0;
    arr[s[0]-'A']++;
    while(st<=en && en<n){
        mx_ct = max(mx_ct,++arr[s[en]-'A']);
        if(en-st+1- mx_ct>k){
            arr[s[st]-'A']--;
            st++;
        }
        mx_l= max(mx_l,en-st+1);
    }
    return mx_l;
}

int main(){
    
    string t="";
    t+= string(5,'a');
    c(t);
    return 0;
}