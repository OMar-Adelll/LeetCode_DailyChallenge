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
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int mn = INT_MAX;
        for (int i = 0; i + k - 1 < n; i++)
        {
            mn = min(mn, nums[i] - nums[i + k - 1]);
        }
        return mn;
    }
};