#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int mod = 1e9 + 7;
int mod1 = 998244353;

void solve()
{
    ll n, i, x;

    cin >> n >> x;
    vector<ll> pr(n + 1, 0), pa(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> pr[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> pa[i];
    }
    int dp[n + 1][x + 1];
    for (i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= x; j++)
        {
            if (j == 0 || i == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], (int)((j < pr[i]) ? 0 : dp[i - 1][j - pr[i]] + pa[i])) % mod;
        }
    }
    cout << dp[n][x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
