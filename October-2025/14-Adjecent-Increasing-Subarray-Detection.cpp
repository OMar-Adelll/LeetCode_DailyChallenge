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
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = sz(nums);
        for (int i = 2 * k - 1; i < n; i++)
        {
            int r = i, l = r - 2 * k + 1;
            int mid = l + k - 1;
            bool can1 = true;
            for (int j = l + 1; j <= mid; j++)
            {
                if (nums[j] <= nums[j - 1])
                {
                    can1 = false;
                    break;
                }
            }
            bool can2 = true;
            for (int j = mid + 2; j <= r; j++)
            {
                if (nums[j] <= nums[j - 1])
                {
                    can2 = false;
                    break;
                }
            }

            if (can1 && can2)
                return true;
        }

        return false;
    }
};