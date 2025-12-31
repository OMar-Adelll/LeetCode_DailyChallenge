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
    vector<vector<int>> dp;
    vector<string> strs;
    int go(int i, int prv)
    {
        if (i == strs[0].size())
            return 0;

        int &ret = dp[i][prv + 1];
        if (~ret)
            return ret;

        int leave = go(i + 1, prv);
        int take = 0;
        if (prv == -1)
        {
            take = 1 + go(i + 1, i);
        }
        else
        {
            bool yes = true;
            for (int r = 0; r < strs.size(); r++)
                if (strs[r][i] < strs[r][prv])
                {
                    yes = false;
                    break;
                }

            if (yes)
                take = 1 + go(i + 1, i);
        }
        return ret = max(leave, take);
    }

    int minDeletionSize(vector<string> &strs)
    {
        int n = strs[0].size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        this->strs = strs;

        return strs[0].size() - go(0, -1);
    }
};