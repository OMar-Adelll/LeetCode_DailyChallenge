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

#define ll long long
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<ll> time(n), rooms(n);

        for (int idx = 0; idx < meetings.size(); idx++)
        {
            int st = meetings[idx][0];
            int end = meetings[idx][1];

            ll dis = end - st;

            int r = -1;
            ll earlistTime = LLONG_MAX;
            int earlistRoom = -1;

            for (int i = 0; i < n; i++)
            {
                if (time[i] < earlistTime)
                {
                    earlistTime = time[i];
                    earlistRoom = i;
                }

                if (time[i] <= st)
                {
                    r = i;
                    break;
                }
            }

            if (r != -1)
            {
                time[r] = end;
                rooms[r]++;
            }
            else
            {
                time[earlistRoom] += dis;
                rooms[earlistRoom]++;
            }
        }

        int room = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (rooms[i] > cnt)
            {
                room = i;
                cnt = rooms[i];
            }
        }

        return room;
    }
};