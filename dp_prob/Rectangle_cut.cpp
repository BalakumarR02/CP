#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    int n, m;

    cin >> n >> m;
    int dp[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
                }
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
                }
            }
        }
    }
    cout << dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
