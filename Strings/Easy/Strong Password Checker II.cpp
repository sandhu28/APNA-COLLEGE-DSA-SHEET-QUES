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

bool strongPasswordCheckerII(string p) {
    int n= p.size();
   if(p.size()<8) {return 0;}
   int one_l= 0;int one_u=0;
   int dig=0;int spe=0;
   int adj=1; //  0 matlab pre hai
   set<char> st;
   string s= "!@#$%^&*()-+";
   for(auto &ch: s){
    st.insert(ch);
   }
   for(int i=0;i<n;i++){
    char ch= p[i];
    if(islower(p[i])){
        one_l |= 1;
    }
    if(isupper(p[i])){
        one_u |= 1;
    }
    if(isdigit(ch)){
        dig |=1;
    }
    if(st.count(ch)>0){
        spe|=1;
    }
    if(i!=n-1){
        if(p[i]==p[i+1]){
            adj &= 0;
        }
    }

   }
   return one_l & one_u & dig & spe & adj;

}


int main(){
    
    return 0;
}