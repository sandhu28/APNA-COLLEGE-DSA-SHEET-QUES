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


vector<vector<int>> levelOrder(TreeNode* root) {
    vvi ans;
    if(root==NULL){
            return ans;
        }
    vi temp;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(1){
        auto n= q.front();
        q.pop();
        if(n!=NULL){
            temp.push_back(n->val);
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else{
            ans.push_back(temp);
            temp.clear();
            if(q.empty()){
                break;
            }
            else{
                q.push(NULL);
            }
        }
    }
    return ans;
}

void dfs(TreeNode* root, vvi &ans,int lev){
    if(root==NULL){return;}
    if(ans.size()== lev){
        ans.push_back(vi());
    }
    ans[lev].push_back(root->val);
    dfs(root->left,ans,lev+1);
    dfs(root->right,ans,lev+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vvi ans;
    dfs(root,ans,0);
    return ans;
}

int main(){
    
    return 0;
}