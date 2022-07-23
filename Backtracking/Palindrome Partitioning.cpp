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

bool isPal(string s){
    int i=0,j=s.size()-1;
    bool f=1;
    while(i<=j){
        if(s[i]!=s[j]){
            f=0;
            break;
        }
        i++;j--;
    }
    return f==1;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    if(s.size()==0){return ans;}
    int n= s.size();
    for(int i=0;i<n;i++){
        if(isPal(s.substr(0,i+1))){
            auto vec= partition(s.substr(i+1));
            for(int k=0;k<vec.size();k++){
                vec[k].insert(vec[k].begin(),s.substr(0,i+1));
                ans.push_back(vec[k]);
            }
        }
    }
    return ans;
}

int main(){
    
    return 0;
}