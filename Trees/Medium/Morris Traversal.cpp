#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
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

vi getIndorder(TreeNode* root){
    vi inorder;
    TreeNode* cur= root;
    while(cur!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur= cur->right;
        }
        else{
            TreeNode* prev= cur->left;
            while(prev->right && prev->right!=cur){
                prev= prev->right;
            }
            if(prev->right==NULL){
                prev->right= cur;
                cur= cur->left;
            }
            else{
                prev->right= NULL;
                inorder.push_back(cur->val);
                cur= cur->right;
            }
        }
    }
    return inorder;
}

int main(){
    
    return 0;
}