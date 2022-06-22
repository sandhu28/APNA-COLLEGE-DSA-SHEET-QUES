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

string discountPrices(string s, int d) {
    stringstream ns(s);
    string word;
    string ans="";
    int n= s.size();
    int i=0;
    while(ns>> word){
        if(word[0]== '$' && word.size()>1){
            // string temp="";
            lli price=0;
            bool f=1;
            for(int i=1;i<word.size();i++){
                if(!isdigit(word[i])){
                    f=0;
                    break;
                }
                price += price*10 + 1LL*(word[i]-'0');
            }
            if(f){
                stringstream inp;
                double dp= (100-d)/(100.0);
                inp << fixed << setprecision(2)<< (dp * price);
                ans += '$' + inp.str() + ' ';
            }
            else{
                ans += word + ' ';
            }

        }
        
    }
    return ans;
}
int main(){
    fast_io;
    string s;
    int d;
    getline(cin,s);
    cin>>d;
    c(discountPrices(s,d));
    return 0;
}