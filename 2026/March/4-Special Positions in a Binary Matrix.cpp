class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0, n = mat.size(), m = mat[0].size();
        for(int i = 0 ;i < n;i++)
        {
            for(int j = 0 ;j < m;j++)
            {
                if(mat[i][j] == 1)
                {
                    bool ok = true;
                    for (int x = 0 ; x < n; x++)
                    {
                        if(x == i) continue;
                        if(mat[x][j] == 1)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) break;

                    for(int y = 0 ; y < m ;y++)
                    {
                        if(y == j) continue;
                        if(mat[i][y] == 1)
                        {
                            ok = false;
                            break;
                        }
                    }


                    if(ok) cnt++;
                }
            }
        }

        return cnt;
    }
};