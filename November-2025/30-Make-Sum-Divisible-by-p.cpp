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
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size(), sum = 0;
        for (auto &num : nums)
            sum = (sum + num) % p;
        if (sum == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int len = n;

        auto safe_mod = [&](int x, int y, int m) -> int
        {
            return ((x - y) + m) % m;
        };

        for (int i = 0; i < n; i++)
        {
            prefix = (prefix + nums[i]) % p;

            int t = safe_mod(prefix, sum, p);
            if (mp.count(t))
                len = min(len, i - mp[t]);

            mp[prefix] = i;
        }

        return len == n ? -1 : len;
    }
};