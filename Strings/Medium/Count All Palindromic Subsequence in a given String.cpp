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

long long int  countPS(string s)
{
    int m= 1e9 + 7;
    int n= s.size();
    long long int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                arr[i][j]=1;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    arr[i][j]=3;
                }
                else{
                    arr[i][j] = 2;
                }
            }
            else{
                if(s[i]==s[j]){
                    arr[i][j]= (1 + ((arr[i+1][j])%m)*1LL + (arr[i][j-1])%m)%m;
                }
                else{
                    arr[i][j] = ((arr[i+1][j]*1LL)%m + (arr[i][j-1]*1LL)%m - (arr[i+1][j-1]*1LL)%m + m)%m;
                }
            }
        }
    }
    return arr[0][n-1]%m;
}

int main(){
    
    return 0;
}