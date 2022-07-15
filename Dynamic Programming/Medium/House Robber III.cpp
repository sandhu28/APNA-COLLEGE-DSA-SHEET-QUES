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

int mxMoney(TreeNode* root,bool f,map<pair<TreeNode*,bool>,int> &m){
    if(root==NULL){
        return 0;
    }
    if(m.find({root,f})!=m.end()){
        return m[{root,f}];
    }
    if(f){
        int take= root->val + mxMoney(root->left,0,m) + mxMoney(root->right,0,m);
        int notTake= mxMoney(root->right,1,m) + mxMoney(root->left,1,m);
        // cout<<root->val<<" "<<max(take,notTake)<<endl;
        return m[{root,f}] = max(take,notTake);
    }
    // cout<<root->val<<" "<<max(mxMoney(root->left,1,m), mxMoney(root->right,1,m))<<endl;
    return m[{root,f}] = (mxMoney(root->left,1,m) + mxMoney(root->right,1,m));
}

vi maxAmount(TreeNode* root){
    vi v(2,0);
    if(root==NULL){
        return v;
    }
    vi left= maxAmount(root->left);
    vi right= maxAmount(root->right);

    v[0]= max(left[0],left[1])+max(right[0],right[1]);
    v[1]= root->val + left[0]+right[0];
    return v;
}

int rob(TreeNode* root) {
    vi ans= maxAmount(root);
    return max(ans[0],ans[1]);
}

int main(){
    
    return 0;
}