#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[1001][5], sum[6] = {0}, j, grp = 0, k, ans = 0;

    cin >> n;

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < 5; i++)
        {
            cin >> a[j][i];
            sum[i] += a[j][i];
        }
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    grp = n / 2;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (sum[i] >= grp && sum[j] >= grp)
            {
                ans = 1;
                ll o = 0, p = 0, q = 0;
                for (k = 0; k < n; k++)
                {
                    if (a[k][i] == 1 && a[k][j] == 0)
                    {
                        o++;
                    }
                    else if (a[k][i] == 0 && a[k][j] == 1)
                    {
                        p++;
                    }
                    else if (a[k][i] == 1 && a[k][j] == 1)
                    {
                        q++;
                    }
                    else
                    {
                        ans = 0;
                        break;
                    }
                }
                if (!ans)
                    continue;
                ll o1 = max((grp - o), (ll)0);
                ll p1 = max((grp - p), (ll)0);
                q -= (o1 + p1);
                if (q >= 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
