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
    int minOperations(vector<int> &nums)
    {
        int mini = INT_MAX, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int g = 0;
            if (nums[i] == 1)
                cnt++;
            for (int j = i; j < nums.size(); j++)
            {
                g = gcd(g, nums[j]);
                if (g == 1)
                {
                    mini = min(mini, j - i + 1);
                }
            }
        }

        if (cnt)
            return nums.size() - cnt;

        if (mini == INT_MAX)
            return -1;

        return nums.size() + mini - 2;
    }
};