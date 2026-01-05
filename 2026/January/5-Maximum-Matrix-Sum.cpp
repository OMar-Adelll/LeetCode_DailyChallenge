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
    ll maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        ll mn = abs(matrix[0][0]), sum = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mn = min((int)mn, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                cnt += (matrix[i][j] < 0);
            }
        }

        if (cnt % 2 == 0)
            return sum;
        return sum - 2 * mn;
    }
};