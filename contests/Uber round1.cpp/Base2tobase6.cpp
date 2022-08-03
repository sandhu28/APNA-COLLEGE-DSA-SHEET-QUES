// int n = arr.size();
// const int mod = 1000000007;
//     vector<vector<int >> dp(n, vector<int >(n, 0));
//     for (int left = n - 1; left >= 0; left--)
//     {
//         for (int right = left + 1; right < n; right += 2)
//         {
//             // choosing two pins b/w left and right (both inclusive) to strike:
//             for (int i = left; i <= right; i++)
//             {
//                 // if the range [left, i-1] have odd number of elements then don't consider it
//                 if ((i - left) % 2 != 0)
//                     continue;
//                 for (int j = i + 1; j <= right; j++)
//                 {
//                     // if the range [j+1, right] have odd number of elements then don't consider it
//                     if ((right - j) % 2 != 0)
//                         continue;
//                     // if the range [i+1, j-1] have odd number of elements then don't consider it
//                     if ((j - i) % 2 == 0)
//                         continue;
//                     // strike the ith and jth pins:
//                     int  leftSection = i > 0 ? dp[left][i - 1] : 0;
//                     int  midSection = (i + 1 < n && j > 0) ? dp[i + 1][j - 1] : 0;
//                     int  rightSection = j < right ? dp[j + 1][right] : 0;
//                     int  beforeLeft = (left == 0) ? 1 : arr[left - 1];
//                     int  afterRight = (right == (n - 1)) ? 1 : arr[right + 1];
//                     int  sum = (leftSection + midSection + rightSection +
//                                      ((arr[i] * arr[j] * beforeLeft * afterRight) % mod)) %
//                                     mod;
//                     dp[left][right] = max(dp[left][right], sum);
//                 }
//             }
//         }
//     }
//     return dp[0][n - 1];