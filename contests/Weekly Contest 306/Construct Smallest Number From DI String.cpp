#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

void recur(string s,string &ans,string &v,int idx,string &nxt){
    int n= v.size();
    if(idx<0){
        // string temp="";
        // for(int i=0;i<v.size();i++){
        //     temp+= v[i];
        // }
        if(v<ans){
            ans= v;
        }
    }
    if(idx==n-1){
        for(int i=1;i<=9;i++){
            string t= to_string(i);
            v = t+ v;
            recur(s,ans,v,idx-1,t);
        }
    }
    int next= stoi(nxt);
    if(s[idx]=='I'){
        for(int i=1;i<next;i++){
            string t= to_string(i);
            v = t+ v;
            recur(s,ans,v,idx-1,t);
        }
    }
    else{
        for(int i=next+1;i<10;i++){
            string t= to_string(i);
            v = t+ v;
            recur(s,ans,v,idx-1,t);
        }
    }
    
}

string smallestNumber(string s)
{
    int n= s.size();
    vector<char> v(n,'9');
    string ans= "";
    string temp= "";
    fo(i,n){
        ans+= 'z';
        temp+= 'z';
    }

}

int32_t main()
{
    int a= 5;
    c(to_string(a));

    return 0;
}