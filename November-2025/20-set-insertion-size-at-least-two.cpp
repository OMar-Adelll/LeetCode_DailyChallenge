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
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int> &v1, const vector<int> &v2)
             {
                 if (v1[1] == v2[1])
                     return v1[0] > v2[0];
                 return v1[1] < v2[1];
             });

        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            int M = 2;
            for (auto &c : ans)
            {
                if (c >= l && c <= r)
                    M--;
            }

            if (M >= 1)
                ans.push_back(r);

            if (M >= 2)
                ans.push_back(r - 1);
        }

        return ans.size();
    }
};