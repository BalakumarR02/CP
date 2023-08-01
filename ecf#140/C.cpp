#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, j;
    cin >> n;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }
    ll dp[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = 2;
        }
    }
    ll mj2 = n, m1 = 0;

    for (i = n - 1; i >= 1; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
            {
                if (v[i][j] == 2)
                {
                    cout << "0\n";
                    return;
                }
                dp[i][j] = 2 * dp[i + 1][i + 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (v[i][j] == 1)
                {
                    if (mj2 <= j)
                    {
                        cout << "0\n";
                        return;
                    }
                    ll po = 1, nn = j - i, nt = n - i, pt = 1;
                    while (nt)
                    {
                        if (nn)
                        {
                            nn--;
                            po *= 2;
                        }
                        nt--;
                        pt *= 2;
                    }
                    dp[i][j] = min(dp[i][j], pt / po);
                }
                else if (v[i][j] == 2 && j <= mj2)
                {
                    mj2 = j;
                    ll po = 1, nn = j - i, nt = n - i, pt = 1;
                    while (nt)
                    {
                        if (nn)
                        {
                            nn--;
                            po *= 2;
                        }
                        pt *= 2;
                        nt--;
                    }
                    dp[i][j] -= min(dp[i][j], pt / po);
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[1][n] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
