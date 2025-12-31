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
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size(), sum = 0;
        for (int i = 1; i < n; i++)
        {
            int l = i - 1, r = i - 1;
            while (i < n && colors[i] == colors[i - 1])
                r++, i++;
            if (l != r)
            {
                int cursum = 0, maxi = -1;
                for (int j = l; j <= r; j++)
                    cursum += neededTime[j], maxi = max(maxi, neededTime[j]);

                sum += (cursum - maxi);
            }
        }

        return sum;
    }
};