#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

// int maxEvents(vector<vector<int>>& events) {
//     sort(all(events),[](vi &a,vi& b){
//         if(a[1]!=b[1]){
//             return a[1]<b[1];
//         }
//         return a[0]<b[0];
//     });
//     int n= events.size();
//     int idx=0;
//     int ct=0;
//     vector<bool> check(1e5+2);
//     for(int i=0;i<n;i++){
//         int st= events[i][0];
//         int en= events[i][1];
//         if(idx<st){
//             check[st]=1;
//             idx= st+1;
//             ct++;
//         }
//         else if(idx>=st && idx<=en){
//             check[idx]= 1;
//             idx++;
//             ct++;
//         }
//         else{
//             continue;
//         }
//     }
//     return ct;
// }

int maxEvents(vector<vector<int>>& events) {
    sort(all(events));
    int n= events.size();
    priority_queue<int,vi,greater<int>> pq;
    int ans=0;
    int i=0;
    for(int d=1;d<=1e5+2;d++){
        while(pq.size() && (pq.top()<d)){
            pq.pop();
        }
        while(i<n && events[i][0]==d){
            pq.push(events[i][1]);
            i++;
        }
        if(pq.size()){
            pq.pop();
            ans++;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}