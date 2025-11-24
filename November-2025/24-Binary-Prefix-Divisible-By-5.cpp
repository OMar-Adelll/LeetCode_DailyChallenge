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
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> ans(n);
        int st = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            st = ((st << 1) + x) % 5;
            ans[i] = (st == 0);
        }

        return ans;
    }
};