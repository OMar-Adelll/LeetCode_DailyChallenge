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

#define all(x) x.begin(), x.end()
class Solution
{
public:
    int dp(vector<int> nums)
    {
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
                cnt++;
            else
                cnt = 1;
            ans = max(ans, cnt);
        }
        return ans + 1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int> &hbars, vector<int> &vbars)
    {
        sort(all(hbars)), sort(all(vbars));
        int x = dp(hbars), y = dp(vbars);
        return min(x, y) * min(x, y);
    }
};