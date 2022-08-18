// #include<iostream>
// #include<bits/stdc++.h>
// #define pii pair<int,int>
// #define int long long int
// #define li long int
// #define vi vector<int>
// #define vd vector<double>
// #define vvd vector<vector<double>>
// #define vvi vector<vector<int>>
// #define vpii vector<pair<int,int>>
// #define vlli vector<lli>
// #define vli vector<li>
// #define vs vector<string>
// #define ss second
// #define ff first
// #define all(x) (x).begin(),(x).end()
// #define fo(i,n) for(int i=0;i<n;i++)
// #define foe(i,k,n) for (int i = k; i < n; ++i)
// #define Repr(i,k,n) for (int i = k; i >= n; --i)
// #define c(n) cout<<n<<endl
// #define z(n) cout<<n<<" " 
// #define nl cout<<endl;
// #define INF INT_MAX
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// using namespace std;

// const int M = 1e9 + 7;
// const int N = 1e5+ 3;

// int ct_dig(int n){
//     int ct=0;
//     while(n>0){
//         n= n/10;
//         ct++;
//     }
//     return ct;
// }
// int countSpecialNumbers(int n) {
//     int dig= ct_dig(n);
//     vi v= {0,9,81,648,4536,27216,136080,544320,1632960}

// }

// int32_t main(){
    
//     return 0;
// }

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the factorial of n
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

// Function to return the count
// of n-digit numbers with
// all distinct digits
int countNum(int n)
{
	if (n > 10)
		return 0;
	return (9 * factorial(9)
			/ factorial(10 - n));
}

// Driver code
int main()
{
	int n = 9;

	cout << countNum(n);

	return 0;
}
