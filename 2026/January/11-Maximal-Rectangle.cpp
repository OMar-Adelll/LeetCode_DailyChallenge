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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        if (n == 1 && m == 1)
            return matrix[0][0] - '0';
        vector<vector<int>> prefix(n, vector<int>(m));
        for (int j = 0; j < m; j++)
        {
            int num = matrix[n - 1][j] - '0';
            prefix[n - 1][j] = num;
            for (int i = n - 2; i >= 0; i--)
            {
                int x = matrix[i][j] - '0';
                if (x == 1)
                {
                    prefix[i][j] = x + prefix[i + 1][j];
                }
                else
                {
                    prefix[i][j] = 0;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mx = prefix[i][j], mn = mx;
                for (int x = j + 1; x < m; x++)
                    mn = min(mn, prefix[i][x]), mx = max(mx, mn * (x - j + 1));

                maxi = max(maxi, mx);
            }
        }

        return maxi;
    }
};