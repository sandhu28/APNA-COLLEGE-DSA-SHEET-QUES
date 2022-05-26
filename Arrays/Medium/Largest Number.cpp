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

bool myCompare(string x,string y){
    string xy= x+y;
    string yx= y+x;
    return xy>yx?1:0;
}
string largestNumber(vector<int>& v) {
    vector<string> vec;
    int n= v.size();
    for(int i=0;i<n;i++){
        vec.push_back(to_string(v[i]));
    }
    sort(vec.begin(),vec.end(),myCompare);
    string ans="";
    for(int i=0;i<n;i++){
        ans+= vec[i];
    }
    return ans;

}

int main(){
    
    return 0;
}