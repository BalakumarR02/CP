#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int mod = 1e9 + 7;
int mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    char a[n + 1][n + 1];
    for (ll x = 1; x <= n; x++)
    {
        for (ll y = 1; y <= n; y++)
        {
            cin >> a[x][y];
        }
    }
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (ll x = 1; x <= n; x++)
    {
        for (ll y = 1; y <= n; y++)
        {
            if (x == 1 && y == 1)
                dp[x][y] = 1;
            else
            {
                dp[x][y] = (((a[x - 1][y] == '*') ? 0 : dp[x - 1][y]) + ((a[x][y - 1] == '*') ? 0 : dp[x][y - 1])) % mod;
            }
        }
    }
    ll ans = ((a[n][n] == '*' || a[1][1] == '*') ? 0 : dp[n][n]);
    cout
        << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
