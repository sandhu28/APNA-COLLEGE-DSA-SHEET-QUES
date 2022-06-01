#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

int highest_pow(int n){
    int x=0;
    while((1<<x)<=n){
        x++;
    }
    return x-1;
}
int it_pow(int a,int b){
    int ans=1;
    while(b>0){
        if((1 &b)){
            ans = ans*a;
        }
        a= a*a;
        b = (b>>1);
    }
    return ans;
}
int countSetBits(int n)
{
    if(n==0){return 0;}
    if(n==1){return 1;}
    int x= highest_pow(n);
    return (x*(it_pow(2,x-1))) + (n-(it_pow(2,x))+1) + countSetBits(n- it_pow(2,x));
}

int main()
{
    c(countSetBits(10));
    return 0;
}