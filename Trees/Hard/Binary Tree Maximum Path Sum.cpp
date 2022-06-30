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
 
int ans= INT_MIN;

// int mxPath(TreeNode* root){
    
//     if(root->left==NULL && root->right==NULL){
//         ans= max(ans,root->val);
//         return root->val;
//     }
//     int temp=INT_MIN;
//     int v1= root->val;
//     temp= max(temp,v1);
//     int vl=0,vr=0;
//     if(root->left){
//         vl= mxPath(root->left);
//         temp= max(temp,vl+v1);
//     }
//     if(root->right){
//         vr= mxPath(root->right);
//         temp= max(temp, vr+ v1);
//     }
//     int ret= temp;
//     if(root->left && root->right){
//         temp= max(temp,v1+ vl+ vr);
//     }
//     ans= max(ans,temp);
//     return ret;
// }

int mxPath(TreeNode* root){
    if(root==NULL){return 0;}

    int v1= root->val;
    int vl=0,vr=0;
    vl= mxPath(root->left);
    vr= mxPath(root->right);

    ans= max(max(v1,v1+vl),max(v1+vr,v1+vr,vl));
    return max(v1,max(v1+vl,v1+vr));
}
int maxPathSum(TreeNode* root) {
    mxPath(root);
    return ans;        
}


int main(){
    
    return 0;
}