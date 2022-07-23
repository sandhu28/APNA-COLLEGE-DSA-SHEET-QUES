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

// int furthestBuilding(vector<int>& h, int b, int l) {
//     set<pii> st; // diff,idx
//     int n= h.size();
//     int sm=0;
//     int idx=-1;
//     int i=0;
//     bool f=1;
//     for(i=1;i<h.size();i++){
//         int d= h[i]-h[i-1];
//         if(d<0){
//             continue;
//         }
//         else{
//             st.insert({d,i});
//             if(st.size()>l){
//                 auto it= st.begin();
//                 sm+= (*it).first;
//                 st.erase(st.begin());
//             }
//             if(sm>b){
//                 f=0;
//                 break;
//             }
//         }
//     }
//     return i-1;

// }


int furthestBuilding(vector<int>& h, int b, int l) {
    priority_queue<int,vector<int>,greater<int>> pq; 
    int n= h.size();
    int sm=0;
    // int idx=-1;
    int i=0;
    // bool f=1;
    for(i=1;i<h.size();i++){
        int d= h[i]-h[i-1];
        if(d<0){
            continue;
        }
        else{
            pq.push(d);
            if(pq.size()>l){
                int top= pq.top();
                sm+= top;
                pq.pop();
            }
            if(sm>b){
                // f=0;
                break;
            }
        }
    }
    return i-1;

}

int main(){
    
    return 0;
}