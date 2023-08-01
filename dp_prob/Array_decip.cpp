#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int mod = 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i, m;

    cin >> n >> m;
    vector<int> a(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (a[i] == 0 || a[i] == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (a[i] == 0 || a[i] == j)
                {
                    dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod + dp[i - 1][j]) % mod;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
