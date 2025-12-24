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
    int minimumBoxes(vector<int> &apple, vector<int> &cap)
    {
        int n = cap.size(), sum = 0;
        for (auto &c : apple)
            sum += c;

        int capsum = 0;
        sort(cap.begin(), cap.end());
        for (int i = cap.size() - 1; i >= 0; i--)
        {
            capsum += cap[i];
            if (capsum >= sum)
                return n - i;
        }

        return cap.size();
    }
};