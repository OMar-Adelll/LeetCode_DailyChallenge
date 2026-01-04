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
    int divSum(int n)
    {
        int sum = 0, cnt = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i * i != n)
                    sum += (n / i), cnt++;
                sum += i, cnt++;
            }
        }

        if (cnt != 4)
            sum = 0;
        return sum;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (auto &c : nums)
            sum += divSum(c);
        return sum;
    }
};