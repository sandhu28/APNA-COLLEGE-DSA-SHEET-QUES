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

// TreeNode* bst(vector<int>& pre,int &idx,int mn,int mx,int n){
//     if(idx==n){
//         return NULL;
//     }
//     int key = pre[idx];
//     if(key>= mn && key<= mx){
//         TreeNode* n= new TreeNode(key);
//         idx++;
//         n->left= bst(pre,idx,mn, key,n);
//         if(!n->left){
//             idx--;
//         }
//         idx++;
//         n->right = bst(pre,idx,key,mx,n);
//         if(!n->right){
//             idx--;
//         }
//         return n;
//     }
//     return NULL;

// }

// TreeNode* bstFromPreorder(vector<int>& preorder) {
//     int idx=0;
//     int mn= INT_MIN;
//     int mx= INT_MAX;
//     int n= preorder.size();
//     bst(preorder,idx,mn,mx,n);
// }

int main(){
    
    return 0;
}