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


int bs(vector<int> &arr,int l,int h,int key){
    while(l<=h){
        int mid= l + (h-l)/2;
        if(arr[mid]== key){
            return mid;
        }
        if(arr[mid]> key){
            h = mid-1;
        }
        else{
            l= mid+1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int idx=-1;
    bool t= false;
    int n= nums.size();
    for(int i=1;i<nums.size()-1;i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            idx= i;
            t= true;
            break;
        }
    }
    if(t){
        int r = bs(nums,idx+1,n-1,target);
        int l= bs(nums,0,idx,target);
        return r>0?r:l;
    }
    return bs(nums,0,n-1,target);
}

int search(vector<int>& arr, int k){
    int n= arr.size();
    int l= 0;int h= n-1;
    int mid=-1;
    while(l<=h){
        mid= l + (h-l)/2;
        if(arr[mid]==k ){return mid;}
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
    return -1;
}
int main(){
    
    return 0;
}