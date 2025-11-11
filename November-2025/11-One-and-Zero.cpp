// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(vec) (vec).begin(), (vec).end()
#define sz(x) (int)(x).size()
#define i(x) (x - 'a')
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define nl '\n'

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &s : strs) {
            int c0 = count(s.begin(), s.end(), '0');
            int c1 = count(s.begin(), s.end(), '1');

            for (int i = m; i >= c0; i--) {
                for (int j = n; j >= c1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
