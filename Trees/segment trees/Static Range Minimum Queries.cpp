// #include <iostream>
// #include <bits/stdc++.h>
// #define pii pair<int, int>
// #define lli long long int
// #define li long int
// #define vi vector<int>
// #define vd vector<double>
// #define vvd vector<vector<double>>
// #define vvi vector<vector<int>>
// #define vpii vector<pair<int, int>>
// #define vlli vector<lli>
// #define vli vector<li>
// #define vs vector<string>
// #define ss second
// #define ff first
// #define all(x) (x).begin(), (x).end()
// #define fo(i, n) for (int i = 0; i < n; i++)
// #define foe(i, k, n) for (int i = k; i < n; ++i)
// #define Repr(i, k, n) for (int i = k; i >= n; --i)
// #define c(n) cout << n << endl
// #define z(n) cout << n << " "
// #define nl cout << endl;
// #define INF INT_MAX
// #define fast_io                       \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// using namespace std;

// const int M = 1e9 + 7;
// const int N = 1e5 + 3;

// void build(vi &v, vi &seg, int idx, int l, int h)
// {
//     if (l == h)
//     {
//         seg[idx] = v[l];
//         return;
//     }
//     int mid = l + (h - l) / 2;
//     build(v, seg, 2 * idx + 1, l, mid);
//     build(v, seg, 2 * idx + 2, mid + 1, h);
//     seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
// }

// int query(vi &seg, int idx, int l, int h, int ql, int qh)
// {
//     if (l >= ql && h <= qh)
//     {
//         return seg[idx];
//     }
//     if ((h < ql) || (l > qh))
//     {
//         return INT_MAX;
//     }
//     int mid = l + (h - l) / 2;
//     int left = query(seg, 2 * idx + 1, l, mid, ql, qh);
//     int right = query(seg, 2 * idx + 2, mid + 1, h, ql, qh);
//     return min(left, right);
// }

// int main()
// {
//     fast_io;
//     int n;
//     cin >> n;
//     int q;
//     cin >> q;
//     vi v(n);
//     fo(i, n)
//     {
//         cin >> v[i];
//     }
//     vi seg(4 * n + 5, INT_MAX);
//     int idx = 0;
//     int l = 0, h = n - 1;
//     build(v, seg, idx, l, h);
//     while (q--)
//     {
//         int ql, qh;
//         cin >> ql >> qh;
//         c(query(seg, idx, l, h, ql - 1, qh - 1));
//     }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

// #define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
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

void build(vi &v, vi &seg, int idx, int l, int h)
{
    if (l == h)
    {
        seg[idx] = v[l];
        return;
    }
    int mid = l + (h - l) / 2;
    build(v, seg, 2 * idx + 1, l, mid);
    build(v, seg, 2 * idx + 2, mid + 1, h);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

// Given an array of n integers, your task is to process q queries of the following types:
// increase each value in range [a,b] by u
// what is the value at position k?

void update(vi &v, vi &lazy, vi &seg, int idx, int l, int h, int val, int updL, int updH)
{
    if (lazy[idx] > 0)
    {
        seg[idx] += lazy[idx] * (h - l + 1);
        if (l != h)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l >= updL && h <= updH)
    {
        seg[idx] += (h - l + 1) * val;
        if (l != h)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
        return;
    }
    if (l > updH || h < updL)
    {
        return;
    }
    int mid = l + (h - l) / 2;
    update(v, lazy, seg, 2 * idx + 1, l, mid, val, updL, updH);
    update(v, lazy, seg, 2 * idx + 2, mid + 1, h, val, updL, updH);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int query(vi &v, vi &lazy, vi &seg, int idx, int l, int h, int k)
{
    if (lazy[idx] > 0)
    {
        seg[idx] += lazy[idx] * (h - l + 1);
        if (l != h)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l == h)
    {
        return seg[idx];
    }
    int mid = l + (h - l) / 2;
    if (k <= mid)
    {
        return query(v, lazy, seg, 2 * idx + 1, l, mid, k);
    }
    return query(v, lazy, seg, 2 * idx + 2, mid + 1, h, k);
}

int32_t main()
{
    fast_io;
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi v(n);
    fo(i, n)
    {
        cin >> v[i];
    }
    vi seg(4 * n + 5, INT_MAX);
    int idx = 0;
    int l = 0, h = n - 1;
    build(v, seg, idx, l, h);
    vi lazy(4 * n + 5, 0);
    while (q--)
    {
        int check;
        cin >> check;
        if (check == 1)
        {
            int a, b, val;
            cin >> a >> b >> val;
            update(v, lazy, seg, idx, l, h, val, a - 1, b - 1);
        }
        else
        {
            int k;
            cin >> k;
            c(query(v, lazy, seg, idx, l, h, k - 1));
        }
    }

    return 0;
}
