#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (i = k; i < n; ++i)
#define Repr(i,k,n) for (i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

/// Approach one using sets ,
/// cannot use unordered_set bz lower_bound works only on sorted ele
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> s;
    for(int i=0;i<nums.size();i++){
        if(s.size()>k){
            s.erase(s.find(nums[i-k-1]));
        }
        auto it = s.lower_bound((long)nums[i]-t);
        if(it!= s.end() && (*it)<= (long)nums[i]+t ){
            return true;
        }
        s.insert((long)nums[i]);
    }
    return false;
}

// Imp approach -- here we'll use BUCKET method. 
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_map<int,int> um;
    for(int i=0;i<nums.size();i++){
        int bkt = nums[i]/(t+1);
        if(nums[i]<0){
            bkt--;
        }
        if(um.find(bkt)!= um.end()){
            return true;
        }
        else{
            um[bkt] = nums[i];
            if(um.find(bkt-1)!= um.end() && um[bkt] -um[bkt-1]<= t){return true;}
            if(um.find(bkt+1)!= um.end() && um[bkt+1] - um[bkt]<= t){return true;}
            if(um.size()>k){
                um.erase(um.find(nums[i-k]));
            }
        }
    }
    return false;
}

int main(){

    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(5);
    us.insert(10);
    

    
    return 0;
}