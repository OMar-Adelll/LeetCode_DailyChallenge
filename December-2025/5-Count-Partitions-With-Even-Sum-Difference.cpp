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
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0, cnt = 0, cursum = 0;
        for (auto &num : nums)
            sum += num;
        for (int i = 0; i < n - 1; i++)
        {
            cursum += nums[i];
            if ((sum - (2 * cursum)) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
