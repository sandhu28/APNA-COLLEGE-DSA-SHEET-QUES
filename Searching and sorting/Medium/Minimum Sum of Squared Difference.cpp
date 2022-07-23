#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
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

// long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

//     int n= nums1.size();
//     priority_queue<int> pq;
//     fo(i,n){
//         pq.push(abs(nums1[i]-nums2[i]));
//     }
//     int k= k1+k2;
//     while(!pq.empty() && k>0){
//         int tp= pq.top();
//         pq.pop();
//         if(tp==0){
//             continue;
//         }
//         tp--;
//         pq.push(tp);
//         k--;
//     }
//     lli ans=0;
//     while(!pq.empty()){
//         int k= pq.top();
//         ans+= 1LL*k*k;
//         pq.pop();
//     }
//     return ans;

// }

long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
{

    int n = nums1.size();
    vi vec(n,0);
    fo(i, n)
    {
        vec[i]= (abs(nums1[i] - nums2[i]));
    }
    int maxDiff= *max_element(all(vec));
    vi diff(maxDiff+1,0);
    fo(i,n){
        diff[vec[i]]++;
    }
    int k = k1 + k2;
    for(int i=maxDiff;i>0;i--){
        if(diff[i]>0){
            int minus= min(diff[i],k);
            diff[i]-= minus;
            diff[i-1]+= minus;
            k-= minus;
        }
    }
    lli ans = 0;
    for(int i= maxDiff;i>0;i--){
        ans+= diff[i]*1LL*i*i;
    }
    return ans;
}

int main()
{

    return 0;
}