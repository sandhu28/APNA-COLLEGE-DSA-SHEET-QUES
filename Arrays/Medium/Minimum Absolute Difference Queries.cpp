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

// Using vectors gave TLE here
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    int n= nums.size();
    int m= queries.size(); 
    vector<int> ans;
    vector<vector<int>> prefix(100001,vector<int>(101,0));
    vector<int> cnt(101,0);
    for(int i=0;i<n;i++){
        cnt[nums[i]]++;
        prefix[i+1]= cnt;
    }
    for(int q=0;q<m;q++){
        int l= queries[q][0];int r= queries[q][1];
        vector<int> new_cnt(101,0);
        for(int j=1;j<101;j++){
            new_cnt[j]= prefix[r+1][j] - prefix[l][j];
        }
        int prev= -1;int min_d= INT_MAX;
        for(int i= 1;i<101;i++){
            if(new_cnt[i]==0){continue;}
            if(prev!=-1 && i-prev<min_d){min_d= i-prev;}
            prev = i;
        }
        if(min_d == INT_MAX){
            ans.push_back(-1);
        }
        else{
            ans.push_back(min_d);
        }
    }
    return ans;
}

// Using arrays gave AC
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    int n= nums.size();
    int m= queries.size(); 
    vector<int> ans(m);
    // vector<vector<int>> prefix(100001,vector<int>(101,0));
    int prefix[100001][101]={};
    // vector<int> cnt(101,0);
    int cnt[101]={};
    for(int i=0;i<n;i++){
        cnt[nums[i]]++;
        for(int j=1;j<101;j++){
            prefix[i+1][j]= cnt[j];
        }
        // prefix[i+1]= cnt;
    }
    for(int q=0;q<m;q++){
        int l= queries[q][0];int r= queries[q][1];
        vector<int> new_cnt(101,0);
        for(int j=1;j<101;j++){
            new_cnt[j]= prefix[r+1][j] - prefix[l][j];
        }
        int prev= -1;int min_d= INT_MAX;
        for(int i= 1;i<101;i++){
            if(new_cnt[i]==0){continue;}
            if(prev!=-1 && i-prev<min_d){min_d= i-prev;}
            prev = i;
        }
        if(min_d == INT_MAX){
            ans[q]=(-1);
        }
        else{
            ans[q]=(min_d);
        }
    }
    return ans;
}

// Using Mo's Algorithm 
void move(int cnt[],int n,int l,int r,int &st,int &en,vector<int>& nums){
    while(st<l){
        cnt[nums[st]]--;
        st++;
    }
    while(st>l){
        st--;
        cnt[nums[st]]++;
    }
    while(en>r){
        cnt[nums[en]]--;
        en--;
    }
    while(en<r){
        en++;
        cnt[nums[en]]++;    
    }
}
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    int n= nums.size();
    int m= queries.size(); 
    vector<int> ans(m);
    vector<vector<int>> sq(m);
    for(int i=0;i<m;i++){
        sq[i] =  {queries[i][0],queries[i][1],i};
    }
    int bsz= sqrt(n);
    sort(sq.begin(),sq.end(),[&bsz](vector<int>& a,vector<int>&b){
        if(a[0]/bsz != b[0]/bsz){
            return (a[0]/bsz) <(b[0]/bsz);
        }
        return a[1]<b[1];
    });
    int cnt[101]={};
    int st= sq[0][0],en= sq[0][0];
    cnt[nums[st]]++;

    for(int i=0;i<m;i++){
        int l= sq[i][0];
        int r= sq[i][1];
        int idx= sq[i][2];
        move(cnt,101,l,r,st,en,nums);
        int prev= -1;int min_d= INT_MAX;
        for(int i= 1;i<101;i++){
            if(cnt[i]==0){continue;}
            if(prev!=-1 && i-prev<min_d){min_d= i-prev;}
            prev = i;
        }
        if(min_d == INT_MAX){
            ans[idx]=(-1);
        }
        else{
            ans[idx]=(min_d);
        }
    }
    return ans;
    
}



void prt(int arr[],int n){
    rep(i,0,n){
        z(arr[i]);
    }
    nl;
}
int main(){
    int arr[4]={1,2,3,4};
    prt(arr,4);
    int na[6]={};
    prt(na,6);
    return 0;
}