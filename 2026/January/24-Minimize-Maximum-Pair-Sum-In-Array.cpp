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
    int minPairSum(vector<int> &nums)
    {
        long long n = nums.size(), mx = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 2; i++)
        {
            long long x = nums[i] + nums[n - i - 1];
            mx = max(mx, x);
        }

        return mx;
    }
};