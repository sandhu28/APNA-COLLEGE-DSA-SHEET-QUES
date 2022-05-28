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

int lps(string s) {
    int n = s.size();
    int arr[n]= {};
    int i=1;int len=0;
    while(i<n){
        if(s[i]== s[len]){
            len++;
            arr[i]= len;
            i++;
        }
        else{
            if(len>0){
                len= arr[len-1];
            }
            else{
                arr[i]=0;
                i++;  
            }
        }
    }
    return len;
}
int main(){
    string s;
    cin>>s;
    c(lps(s));
    
    return 0;
}