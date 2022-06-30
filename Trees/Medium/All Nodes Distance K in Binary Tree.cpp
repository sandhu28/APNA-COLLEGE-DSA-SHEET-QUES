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

vector<int> ans;

void nodesInSubtree(TreeNode* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        ans.push_back(root->val);
        return;
    }
    nodesInSubtree(root->left,k-1);
    nodesInSubtree(root->right, k-1);
}

int NodesAtKdist(TreeNode* root, TreeNode* t,int k){

    if(root==NULL || k<0){
        return -1;
    }

    if(root== t){
        nodesInSubtree(root,k);
        return 0;
    }
    int dl= NodesAtKdist(root->left,t,k);
    int dr= NodesAtKdist(root->right,t,k);
    if(dl!=-1){
        if(dl+1==k ){
            ans.push_back(root->val);
        }
        else{
            nodesInSubtree(root->right,k-dl-2);
        }
        return dl+1;
    }
    if(dr!=-1){
        if(dr+1==k ){
            ans.push_back(root->val);
        }
        else{
            nodesInSubtree(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    NodesAtKdist(root,target,k);
    return ans;
        
}


int main(){
    
    return 0;
}