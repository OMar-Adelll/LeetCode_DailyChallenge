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
    vector<int> nums;
    vector<vector<int>> dp;
    int rec(int idx, int Mod)
    {
        if (idx == nums.size())
            return (Mod == 0 ? 0 : -INT_MAX);

        int &ret = dp[idx][Mod];
        if (~ret)
            return ret;

        int ans = max(nums[idx] + rec(idx + 1, (nums[idx] + Mod) % 3),
                      rec(idx + 1, Mod));

        return ret = ans;
    }

    int maxSumDivThree(vector<int> &a)
    {
        nums = a;
        dp.assign(a.size() + 1, vector<int>(3, -1));
        return rec(0, 0);
    }
};