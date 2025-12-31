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
    int countValidSelections(vector<int> &nums)
    {
        int n = sz(nums);
        vector<int> pre = nums;
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];

        // Array :   1 0 2 0 3
        // Prefix :  1 1 3 3 6

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                int l = pre[i];
                int r = pre[n - 1] - pre[i];
                if (l == r)
                    cnt += 2;
                else if (l == r - 1 || l - 1 == r)
                    cnt += 1;
            }
        }

        return cnt;
    }
};