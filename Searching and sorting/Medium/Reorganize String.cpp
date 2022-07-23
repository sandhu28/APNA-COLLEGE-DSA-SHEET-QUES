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

string reorganizeString(string s) {
    priority_queue<pair<int,char>> pq;
    int n=s.size();
    vi arr(n,0);
    fo(i,n){
        arr[s[i]-'a']++;
    }
    fo(i,26){
        if(arr[i]!=0){
            pq.push({arr[i],(char)(i+'a')});
        }
    }
    string ans="";
    while(!pq.empty()){
        auto pr1= pq.top();
        ans+= pr1.second;
        pr1.first--;
        pq.pop();
        if(pq.empty() && pr1.first>0){
            return "";
        }
        auto pr2= pq.top();
        ans+= pr2.second;
        pr2.first--;
        pq.pop();
        if(pr2.first!=0){
            pq.push(pr2);
        }
        if(pr1.first>0){
            pq.push(pr1);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}