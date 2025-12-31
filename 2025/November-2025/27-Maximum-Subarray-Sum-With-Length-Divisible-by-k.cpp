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
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        vector<long long> Min(n, LLONG_MAX);
        long long maxi = -LLONG_MAX;
        for (int r = 0; r <= n; r++)
        {
            int len = r % k;

            if (Min[len] != LLONG_MAX)
                maxi = max(maxi, prefix[r] - Min[len]);

            Min[len] = min(prefix[r], Min[len]);
        }

        return maxi;
    }
};