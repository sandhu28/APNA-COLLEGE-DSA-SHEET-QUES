#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool search(vector<int>& arr, int k) {
    int n= arr.size();
    int l= 0;int h= n-1;
    int mid=-1;
    while(l<=h){
        mid= l + (h-l)/2;
        if(arr[mid]==k ){return true;}
        if(arr[mid]==arr[l] && arr[mid]== arr[h]){
            l++;
            h--;continue;
        }
        if(arr[mid]>=arr[l]){
            if(k>=arr[l] && k<arr[mid]){
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        else{
            if(k>arr[mid] && k<= arr[h]){
                l= mid+1;
            }
            else{
                h= mid-1;
            }

        }
    }
    return false;
}

int main(){
    
    return 0;
}