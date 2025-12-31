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
    long long getDescentPeriods(vector<int> &a)
    {
        long long cnt = 1, ans = 0;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i - 1] == a[i] + 1)
            {
                cnt++;
            }
            else
            {
                ans += cnt * (cnt + 1) / 2;
                cnt = 1;
            }
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
};