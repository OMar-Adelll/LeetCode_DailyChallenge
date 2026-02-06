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
    int minRemoval(vector<int> &nums, int k)
    {
        if (sz(nums) == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int M = INT_MAX;
        for (int l = 0; l < sz(nums); l++)
        {
            int r = upper_bound(nums.begin(), nums.end(), (long long)nums[l] * k) - nums.begin();
            int len = r - l;
            M = min(M, sz(nums) - len);
        }

        return (M == sz(nums) ? 0 : M);
    }
};