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

int videoStitching(vector<vector<int>>& clips, int time) {
        int n= clips.size();
    sort(all(clips),[](vi &a,vi &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    });      

    int en=clips[0][1];
    if(clips[0][0]!=0){return -1;}
    if(en>=time){
        return 1;
    }
    int i=1;
    int ct=1;
    while((i<n)){
        int temp=-1;
        bool f=0;
        while((i<n)&& (clips[i][0]<=en)){
            if(clips[i][1]>en){
                f=1;
                temp= max(temp,clips[i][1]);
            }
            i++;
        }
        if(!f){return -1;}
        ct++;
        en= temp;
        if(en>=time){
            return ct;
        }
    }
    if(en<time){
        return -1;
    }
    return ct;
    }

int main(){
    
    return 0;
}