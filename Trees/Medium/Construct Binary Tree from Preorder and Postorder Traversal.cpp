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

TreeNode* constructTree(vi &pre,vi &post,int &idx,int l,int h){
    if((l>h )|| idx>= pre.size()){
        return NULL;
    }
    if(l==h){
        return new TreeNode(pre[idx]);
    }
    TreeNode* node= new TreeNode(pre[idx]);
    int mid= (l+ h-1)/2;
    idx++;
    node->left= constructTree(pre,post,idx,l,mid);
    idx++;
    node->right = constructTree(pre,post,idx,mid+1,h-1);
    return node;
}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int idx=0;
    return constructTree(pre,post,idx,0,pre.size()-1)   ;     
}

int main(){
    
    return 0;
}