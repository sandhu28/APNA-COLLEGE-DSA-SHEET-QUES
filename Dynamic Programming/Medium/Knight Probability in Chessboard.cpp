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

vpii mov={{-2,1},{-2,-1},{2,1},{2,-1},{1,-2},{-1,-2},{1,2},{-1,2}};

bool isValid(int i,int j,int n){
    return (i>=0) && (j>=0)&& (i<n) && (j<n);
}

double knightProbability(int n, int k, int r, int c) {
    vvd curr(n,vd(n,0));
    vvd next(n,vd(n,0));
    curr[r][c]= 1;
    for(int m=1;m<=k;m++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(curr[i][j]!=0){
                    for(auto &pr: mov){
                        int ni= i-pr.first;
                        int nc= j-pr.second;
                        if(isValid(ni,nc,n)){
                            next[ni][nc] += curr[i][j]*(1/8.0);
                        }
                    }
                }
            }
        }
        curr= next;
        vvd temp(n,vd(n,0));
        next= temp;
    }
    double ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+= curr[i][j];
        }
    }
    return ans;
}

int main(){
    
    return 0;
}