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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// void noOfPaths(TreeNode* root,long long ts,int &paths){
        
//         if(root==NULL){
//             return ;
//         }
//         if(ts-1LL*root->val==0){
//             paths+=1;
//         }
//         noOfPaths(root->left,ts-1LL*root->val,paths); 
//         noOfPaths(root->right,ts-1LL*root->val,paths);
        
//     }
//     int pathSum(TreeNode* root, int ts) {
//         if(root==NULL){
//             return 0;
//         }
//         int paths=0;
//         noOfPaths(root,1LL*ts,paths);
//         paths+= pathSum(root->left,ts);
//         paths+= pathSum(root->right,ts);
        
//         return paths;
//     }

int recur(TreeNode* root,int ts,lli sm,map<lli,int> &m){
    if(root==NULL){
        return 0;
    }
    sm+= root->val;
    int ans=0;
    if(m.find(sm-1LL*ts)!=m.end()){
        ans+= m[sm-1LL*ts];
    }
    m[sm]+=1;
    ans+= recur(root->left,ts,sm,m) + recur(root->right,ts,sm,m);
    m[sm]--;
    return ans;
}

int pathSum(TreeNode* root, int ts) {
    map<lli,int> m;
    m.insert({0,1});
    return recur(root,ts,0,m);
}

int main(){
    
    return 0;
}