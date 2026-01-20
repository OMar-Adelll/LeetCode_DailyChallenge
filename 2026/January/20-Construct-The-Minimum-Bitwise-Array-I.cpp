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
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            bool found = false;
            for (int num = 1; num <= nums[i]; num++)
            {
                if ((num | (num + 1)) == nums[i])
                {
                    ans[i] = num;
                    found = true;
                    break;
                }
            }
            if (!found)
                ans[i] = -1;
        }
        return ans;
    }
};