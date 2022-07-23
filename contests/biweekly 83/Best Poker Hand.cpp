#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

string bestHand(vector<int>& ranks, vector<char>& suits) {
    vi vec(14,0);
    int rsz= ranks.size();
    int ssz= suits.size();
    bool one=0,two=0,three=0,four=0;
    vector<string> str={"Flush","Three of a Kind","Pair","High Card"};
    fo(i,5){
        vec[ranks[i]]++;
        if(vec[ranks[i]]==2){three=1;}
        if(vec[ranks[i]]==3){
            two=1;
        }
    }
    char ch= suits[0];
    int ct=0;
    fo(i,5){
        if(suits[i]==ch){
            ct++;
        }
    }
    if(ct==5){
        one=1;
    }
    if(one){
        return str[0];
    }
    if(two){
        return str[1];
    }
    if(three){
        return str[2];
    }
    return str[3];

}

int main(){
    
    return 0;
}