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

class Solution {
public:

    TreeNode* construct_Tree(vi &pre,vi &ino, int i,int j,int &idx){
        if(idx== pre.size() || (i>j)){
            return NULL;
        }
        TreeNode* n= new TreeNode(pre[idx]);
        if(i==j){
            return n;
        }
        int curr=-1;
        for(int k=i;k<=j;k++){
            if(ino[k]==pre[idx]){
                curr= k;
                break;
            }
        }
        if(curr-1>= i){
            idx++;
        }
        n->left= construct_Tree(pre,ino,i,curr-1,idx);
        if(curr+1<=j){
            idx++;
        }
        n->right= construct_Tree(pre,ino,curr+1,j,idx);
        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return construct_Tree(preorder,inorder,0,preorder.size()-1,idx);
    }
};


int main(){
    
    return 0;
}