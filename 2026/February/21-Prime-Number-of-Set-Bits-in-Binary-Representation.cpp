// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i(x) (x - 'a')
#define nl '\n'
#define sz(x) (int)(x).size()
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define all(vec) (vec).begin(), (vec).end()
class Solution
{
public:
    const int N = 40;
    vector<bool> Is_prime;
    void sieve()
    {
        Is_prime[0] = Is_prime[1] = false;
        for (int i = 2; i * i < N; i++)
        {
            if (Is_prime[i])
            {
                for (int j = i * i; j < N; j += i)
                    Is_prime[j] = false;
            }
        }
    }

    int countPrimeSetBits(int left, int right)
    {
        Is_prime.assign(40, true);
        sieve();
        int cnt = 0;
        for (int i = left; i <= right; i++)
        {
            int x = __builtin_popcount(i);
            if (Is_prime[x])
                cnt++;
        }

        return cnt;
    }
};