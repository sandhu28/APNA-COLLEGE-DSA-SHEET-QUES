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


// Gave TLE 
int superEggDrop(int k, int n) {
    vvi dp(k+1,vi(n+1,0));
    fo(i,k+1){
        fo(j,n+1){
            if(j==0){
                dp[i][j] = 0;
            }
            else if(i==1){
                dp[i][j] = j;
            }
            else if(j==1 && i!=0){
                dp[i][j] = 1;
            }
            else{
                continue;
            }
        }
    }
    for(int e=2;e<k+1;e++){
        for(int f=2;f<n+1;f++){
            int ans= INT_MAX;
            for(int i=1;i<=f;i++){
                int temp= max(dp[e-1][i-1],dp[e][f-i]);
                ans= min(temp+1,ans);
            }
            dp[e][f]= ans;
        }
    }
    return dp[k][n];
}

// No TLE but time= 1264 ms to run using binary search
int superEggDrop(int k, int n) {
    vvi dp(k+1,vi(n+1,0));
    fo(i,k+1){
        fo(j,n+1){
            if(j==0){
                dp[i][j] = 0;
            }
            else if(i==1){
                dp[i][j] = j;
            }
            else if(j==1 && i!=0){
                dp[i][j] = 1;
            }
            else{
                continue;
            }
        }
    }
    for(int e=2;e<k+1;e++){
        for(int f=2;f<n+1;f++){
            int ans= INT_MAX;
            int l= 1,h= f;
            while(l<=h){
                int mid= l+ (h-l)/2;
                int left= dp[e-1][mid-1];
                int right= dp[e][f-mid];
                int temp= max(left,right);
                ans= min(temp + 1,ans);
                if(left<right){
                    l= mid+1;
                }
                else{
                    h= mid-1;
                }
            }
            dp[e][f]= ans;
        }
    }
    return dp[k][n];
}

// Awesome solution in k*n time complexity
int superEggDrop(int k, int n) {
    vvi dp(n+1,vi(k+1,0));
    int m=0;
    while(dp[m][k]<n){
        m++;
        foe(i,1,k+1){
            dp[m][i]= dp[m-1][i-1]+dp[m-1][i] + 1;
        }
    }
    return m;

}

int main(){
    
    return 0;
}