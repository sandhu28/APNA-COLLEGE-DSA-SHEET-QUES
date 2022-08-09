#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
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

vvi matrixMul(vvi &a, vvi &b)
{
    int n = a.size();
    int m = a[0].size();
    int t = b[0].size();
    vvi ans(n, vi(t));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int temp=0;
            for (int k = 0; k < m; k++)
            {
                temp= (temp%M+ (a[i][k]* b[k][j])%M)%M;
                
            }
            ans[i][j]= temp;
        }
    }
    return ans;
}

vvi identity(vvi &a){
    int n= a.size();
    int m= a[0].size();
    vvi I(n,vi(m,0));
    int i=0,j=0;
    while(i<n && j<m){
        I[i][j]=1;
        i++;j++;
    }
    return I;
}

// vvi matrix_expo(vvi &a,int b){
//     if(b==0){
//         return identity(a);
//     }
//     vvi x= matrix_expo(a,b/2);
//     if(b&1){
//         vvi temp= matrixMul(x,x);
//         return matrixMul(temp,a);
//     }
//     return matrixMul(x,x);
// }

vvi matrix_expo(vvi &a,int b){
    vvi ans=identity(a);
    while(b>0){
        if(b&1){
            ans= matrixMul(ans,a);
        }
        b>>=1;
        a= matrixMul(a,a);
    }
    return ans;
}


int32_t main(){
    int n;cin>>n;
    if(n==0){
        c('0');
        return 0;
    }
    if(n==1){
        c('1');
        return 0;
    }
    vvi v(2,vi(2,1));
    v[1][1]=0;
    vvi vec(2,vi(1,1));
    vvi temp= matrix_expo(v,n-2);
    vvi ans= matrixMul(temp,vec);
    c(ans[0][0]);
    
    
    return 0;
}