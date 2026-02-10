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
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        set<int> odd, even;
        for (; l < n; l++)
        {
            odd.clear(), even.clear();
            for (int r = l; r < n; r++)
            {
                if (nums[r] % 2)
                    odd.insert(nums[r]);
                else
                    even.insert(nums[r]);

                if (odd.size() == even.size())
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};