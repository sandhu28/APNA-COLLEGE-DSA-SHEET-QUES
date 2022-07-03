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

// void swapVal(TreeNode** f,TreeNode** l){
//     int temp = (*f)->val;
//     (*f)->val= (*l)->val;
//     (*l)->val= temp;
// }
//     void calPtrs(TreeNode* root,TreeNode** prev,TreeNode** first, TreeNode** mid,TreeNode** last){
//     if(root==NULL){
//         return ;
//     }
//     calPtrs(root->left,prev,first,mid,last);
//     if((*prev) && (root->val)< (*prev)->val){
//         if(!(*first)){
//             *first= *prev;
//             *mid= root;
//         }
//         else{
//             *last= root;
//         }
//     }
//     *prev=root;
//     calPtrs(root->right,prev,first,mid,last);
// }

// void recoverTree(TreeNode* root) {
//     if(root==NULL){
//         return;
//     }
//     TreeNode* prev,*first,*mid,*last;
//     prev=first=mid=last= NULL;
//     calPtrs(root,&prev,&first,&mid, &last);

//     if((first) &&( last)){
//         swapVal(&first,&last);
//     }
//     else{
//         swapVal(&first,&mid);
//     }
// }

void swapVal(TreeNode* f,TreeNode* l){
    int temp = (f)->val;
    (f)->val= (l)->val;
    (l)->val= temp;
}
    void calPtrs(TreeNode* root,TreeNode* prev,TreeNode* first, TreeNode* mid,TreeNode* last){
    if(root==NULL){
        return ;
    }
    calPtrs(root->left,prev,first,mid,last);
    if((prev) && (root->val)< (prev)->val){
        if(!(first)){
            first= prev;
            mid= root;
        }
        else{
            last= root;
        }
    }
    prev=root;
    calPtrs(root->right,prev,first,mid,last);
}

void recoverTree(TreeNode* root) {
    if(root==NULL){
        return;
    }
    TreeNode prev,first,mid,last;
    prev=first=mid=last= NULL;
    calPtrs(root,&prev,&first,&mid, &last);

    if((first.left || first.right) && (last.left || last.right)){
        swapVal(&first,&last);
    }
    else{
        swapVal(&first,&mid);
    }
}
int main(){
    
    return 0;
}