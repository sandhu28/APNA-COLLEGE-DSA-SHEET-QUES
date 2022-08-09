#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;


// Basic operations

// +,-,%,*,division and bitwise operators
// ^,|,&
// TC is no of basic operations a program performs

// Binary exponentiation
// (3^16) calculate.
// mutli 3 16 times is very costly but if we observe that if we know 3^8 then by just doing one more * we can get
// 3^16 , So in general to calculate a^b we need to express b in binary
//

int recur_a_to_b(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int x = recur_a_to_b(a, b / 2);

    if (b & 1)
    {
        return x * x * a;
    }
    return x * x;
}

int iterative_a_to_b(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a;
        }
        b >>= 1;
        a = a * a;
    }
    return ans;
}

// Applications of exponentiation

// 1. Matrix multiplication
// A.A.A.A.A.A = A^6= (A^3)^2 =  ((A^1)^2)*A)^2

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
                temp+= a[i][k]* b[k][j];
                
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

vvi matrix_expo(vvi &a,int b){
    if(b==0){
        return identity(a);
    }
    vvi x= matrix_expo(a,b/2);
    if(b&1){
        vvi temp= matrixMul(x,x);
        return matrixMul(temp,a);
    }
    return matrixMul(x,x);
}

// 2. Linear transformations 
// x,y -> (x+y,2*y-x) let's say we keep on doing this transformation say 100 times what would final points??
// this can be a 2*2 matrix being mul by 2*1 matrix [[1,1],[-1,2]]*[[x],[y]]==== A*X
// repeative thing would become (A^100)*X. and A^100 can be calculated in 
//Log(100)*(no of comput for two matrices)time

// 3. Calculating fibonacci numbers efficiently. 
// [[1,1],[1,0]]*[[1],[1]] = [[2],[1]] ==> (A^n) *X= [fib(n+1),fib(n)]
// Even dp gives O(n) time but this method can do it in O(log(n)) time.



int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    vvi a(n,vi(m));
    vvi b(m,vi(t));
    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
        }
    }
    fo(i,m){
        fo(j,t){
            cin>>b[i][j];
        }
    }
    vvi ans= matrix_expo(a,10);
    int r= ans.size();
    int c= ans[0].size();
    fo(i,r){
        fo(j,c){
            z(ans[i][j]);
        }
        nl;
    }

    


    return 0;
}