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

int findIdx(int val,vi &post,int st,int en){
    for(int i=st;i<=en;i++){
        if(post[i]==val){
            return i;
        }
    }
    return -1;
}

TreeNode* treePostPre(vi &pre,vi &post,int preSt,int preEn, int postST,int postEn){
    if(preSt > preEn){
        return NULL;
    }
    if(preSt== preEn){
        return new TreeNode(pre[preSt]);
    }
    TreeNode* root= new TreeNode(pre[preSt]);
    int leftSubStPre= preSt + 1;
    int leftSubEnPost= findIdx(pre[leftSubStPre],post,postST,postEn);
    int leftSubEnPre = leftSubStPre + (leftSubEnPost - postST);

    root->left= treePostPre(pre,post,leftSubStPre,leftSubEnPre,postST,leftSubEnPost);
    root->right= treePostPre(pre,post,leftSubEnPre+1,preEn,leftSubEnPost+ 1, postEn-1);
    return root;

}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

    return treePostPre(pre,post,0,pre.size()-1,0,pre.size()-1);
}

int main(){
    
    return 0;
}