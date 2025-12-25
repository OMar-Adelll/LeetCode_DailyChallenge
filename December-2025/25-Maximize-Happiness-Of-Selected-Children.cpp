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
    long long maximumHappinessSum(vector<int> &hap, int k)
    {
        sort(hap.rbegin(), hap.rend());
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += max(0LL, (long long)hap[i] - i);

        return (long long)sum;
    }
};





//-- Python Solution --// 
// class Solution:
//     def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
//         sum, st = 0,0
//         happiness.sort()
//         for hap in reversed(happiness):
//             if st == k : break
//             sum += max(0, hap - st)
//             st += 1

//         return sum 