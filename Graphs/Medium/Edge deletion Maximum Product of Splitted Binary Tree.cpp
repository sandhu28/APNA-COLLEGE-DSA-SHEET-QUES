#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int total = 0;
long long int res = 1;
int M = 1e9 + 7;
int dfs(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int curr_sum = (root->val) + dfs(root->left) + dfs(root->right);
    return curr_sum;
}
int dfs2(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int subtreeSum = (root->val) + dfs2(root->left) + dfs2(root->right);
    // cout<<(root->val)<<" "<<subtreeSum<<endl;
    long long int pro = (subtreeSum)*1LL * (total - subtreeSum);
    res = max(res, pro);
    return subtreeSum;
}
int maxProduct(TreeNode *root)
{

    total += dfs(root);
    dfs2(root);

    return (int)(res % M);
}

int main()
{

    return 0;
}