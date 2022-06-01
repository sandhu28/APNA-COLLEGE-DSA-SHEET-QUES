#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


int minOps(string& A, string& B)
{
    int m = A.length(), n = B.length();
 
    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in A
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // subtract count for every character in B
    for (int i = 0; i < n; i++)
        count[B[i]]--;
    // Check if all counts become 0
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
 
    // This part calculates the number of operations
    // required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j]) {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0) {
            i--;
            j--;
        }
    }
    return res;
}

int main(){
    
    string a,b;
    cin>>a>>b;
    c(minOps(a,b));
    return 0;
}