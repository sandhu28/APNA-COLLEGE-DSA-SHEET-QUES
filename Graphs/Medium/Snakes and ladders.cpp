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
#define all(x) (x).begin(), (x).end()
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

// int bfs(vi &v, vi &lev, int k,vvi &vis)
// {
//     queue<pii> q; // 0 matlab no snake or ladder
//     vis[0][1]=1;
//     vis[1][1]=1;
//     q.push({1, 0});
//     lev[1] = 0;
//     int lev=0;
//     // c(k);
//     while (!q.empty())
//     {
//         // c(k);
//         int cn = q.front().first;
//         int temp = q.front().second;
//         // z(cn);z(temp);
//         // for(int i=1;i<=k;i++){
//         //     z(lev[i]);
//         // }
//         // nl;
//         q.pop();
//         if (temp == 0)
//         {

//             if (v[cn] != -1)
//             {
//                 if (lev[v[cn]] > lev[cn])
//                 {
//                     lev[v[cn]] = lev[cn];
//                     q.push({v[cn], 1});
//                     continue;
//                 }
//             }
//             // c("yes");
//             else{
//                 for (int a = 1; a <= 6; a++)
//             {
//                 // c("yes");
//                 int new_n = a + cn;
//                 // c(new_n);
//                 // if(new_n<=k){c(lev[new_n]);}
//                 if ((new_n <= k) && ((lev[new_n]) > (lev[cn] + 1)))
//                 {
//                     // c("yes");
//                     q.push({new_n, 0});
//                     lev[new_n] = lev[cn] + 1;
//                 }
//             }
//             }
//         }
//         else
//         {
//             // c("yes");
//             for (int a = 1; a <= 6; a++)
//             {
//                 int new_n = a + cn;
//                 if (new_n <= k && (lev[new_n] > lev[cn] + 1))
//                 {
//                     q.push({new_n, 0});
//                     lev[new_n] = lev[cn] + 1;
//                 }
//             }
//         }
//         if(lev[k]!= INF){
//             // c("yes");
//             // c(k);
//             // for(int i=1;i<=k;i++){
//             // z(lev[i]);
//         // }
//         // nl;
//             return lev[k];
//         }
//     }
//     return -1;
// }

int bfs(vi &v, int k, vvi &vis)
{
    queue<pii> q; // 0 matlab no snake or ladder
    vis[0][1] = 1;
    vis[1][1] = 1;
    vvi level(2,vi(k+1,INF));
    q.push({1, 0});
    // int lev = 0;
    level[0][1]= level[0][1]=0;
    // c(k);
    while (!q.empty())
    {
        // c(k);
        int sz = q.size();
        while (sz--)
        {
            int cn = q.front().first;
            int temp = q.front().second;
            q.pop();
            // if(cn== k){
            //     return level[cn];
            // }
            if (temp == 0)
            {
                if (v[cn] != -1)
                {
                    if (vis[1][v[cn]] == 0)
                    {
                        q.push({v[cn], 1});
                        vis[1][v[cn]] = 1;
                        level[1][v[cn]] = level[0][cn];
                        // level[v[cn]]= min(level[v[cn]],level[cn]);
                    }
                }
                // c("yes");
                else
                {
                    for (int a = 1; a <= 6; a++)
                    {
                        // c("yes");
                        int new_n = a + cn;
                        // c(new_n);
                        // if(new_n<=k){c(lev[new_n]);}
                        if ((new_n <= k) && vis[0][new_n] == 0)
                        {
                            // c("yes");
                            q.push({new_n, 0});
                            vis[0][new_n] = 1;
                            level[0][new_n]= level[0][cn]+1;
                        }
                    }
                }
            }
            else
            {
                // c("yes");
                for (int a = 1; a <= 6; a++)
                {
                    int new_n = a + cn;
                    if ((new_n <= k) && vis[0][new_n] == 0)
                    {
                        q.push({new_n, 0});
                        vis[0][new_n] = 1;
                        level[0][new_n]= level[1][cn]+1;
                    }
                }
            }
        }
        // lev++;
    }
    int ans= min(level[0][k],level[1][k]);
    return ans==INT_MIN?-1:ans;
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vi v((n * n) + 1, 0);
    int nsq = n * n;
    vvi vis(2, vi(nsq + 1, 0));
    int k = 1;
    bool right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!right)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                v[k] = board[i][j];
                k++;
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                v[k] = board[i][j];
                k++;
            }
        }
        right ^= 1;
    }
    // for(int i=0;i<=nsq;i++){
    //     z(v[i]);
    // }
    // nl;
    // vi lev(nsq + 1, INF);
    return bfs(v, nsq, vis);
}

int main()
{

    return 0;
}