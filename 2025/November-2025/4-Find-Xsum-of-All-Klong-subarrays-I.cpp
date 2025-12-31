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
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        int l = 0, r = k - l - 1, ans_idx = 0;
        vector<int> ans(n - k + 1, 0);
        for (; r < n; r++)
        {
            vector<pair<int, int>> freq(55, {0, 0});
            for (int i = l; i <= r; i++)
                freq[nums[i]].first = nums[i], freq[nums[i]].second++;

            sort(freq.begin(), freq.end(), [&](pair<int, int> x, pair<int, int> y)
                 {
                if(x.second != y.second)
                    return x.second > y.second;

                return x.first > y.first; });

            int M = x, idx = 0, sum = 0;
            while (M--)
            {
                sum += (freq[idx].first * freq[idx].second);
                idx++;
            }

            ans[ans_idx++] = sum;
            l++;
        }

        return ans;
    }
};