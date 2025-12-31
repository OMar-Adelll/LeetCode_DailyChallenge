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

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m + 1, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                bool can = true;
                for (int r = 0; r < n; r++)
                {
                    if (strs[r][j] > strs[r][i])
                    {
                        can = false;
                        break;
                    }
                }
                if (can)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int mx = 0;
        for (auto &c : dp)
            mx = max(mx, c);
        return m - mx;
    }
};