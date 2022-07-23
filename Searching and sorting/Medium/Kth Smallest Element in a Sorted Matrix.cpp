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

// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     priority_queue<int> pq;
//     int n= matrix.size();
//     fo(i,n){
//         fo(j,n){
//             pq.push(matrix[i][j]);
//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }
//     }
//     return pq.top();
// }

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<vi,vvi,greater<vi>> pq;
    int n= matrix.size();
    fo(j,n){
        vi temp(3);
        temp= {matrix[0][j],0,j};
        pq.push(temp);
    }
    fo(i,k-1){
        vi top= pq.top();
        if(top[1]==n-1){continue;}
        pq.pop();
        pq.push({matrix[top[1]+1][top[2]],top[1]+1,top[2]});
    }
    return pq.top()[0];
}

int main(){
    
    return 0;
}