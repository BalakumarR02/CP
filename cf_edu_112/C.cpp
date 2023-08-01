#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, m, a[2][100001], i, j, sum[2] = {0};

    cin >> t;
    while (t--)
    {
        cin >> m;
        for (i = 0; i < 2; i++)
        {
            sum[i] = 0;
            for (j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (i == 0)
                    sum[i] += a[i][j];
            }
        }
        sum[0] -= (a[0][0]);
        (a[0][0]) = 0;
        j = 0;

        for (i = 0; i < 2; i++)
        {
            for (; j < m; j++)
            {

                if (i == 0)
                {
                    sum[i] -= a[i][j];
                    sum[1] += a[1][j];
                }

                if ((sum[0]) < (sum[1]) && i == 0)
                {
                    i++;
                    sum[i] -= a[i][j];
                }
            }
        }
        cout << max(sum[0], sum[1]) << endl;
    }
    return 0;
}
