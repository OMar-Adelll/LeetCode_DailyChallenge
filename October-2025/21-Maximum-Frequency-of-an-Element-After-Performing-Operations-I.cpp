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
#define f first
#define s second

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int ope)
    {
        sort(all(nums));
        map<int, int> m;
        set<int> uni;
        for (auto &c : nums)
            m[c]++, uni.insert(c + k), uni.insert(c - k), uni.insert(c);

        vector<int> numbers(all(uni));
        int rs = 1;
        for (auto &c : numbers)
        {
            int mnval = c - k;
            int mxval = c + k;
            
            int l = lower_bound(all(nums), mnval) - numbers.begin();
            int r = upper_bound(all(nums), mxval) - numbers.begin();

            if (r - l > 0)
            {
                int mx_op = r - l - m[c];
                int mx_fr = min(mx_op, ope) + m[c];
                updmax(rs, mx_fr);
            }
        }

        return rs;
    }
};