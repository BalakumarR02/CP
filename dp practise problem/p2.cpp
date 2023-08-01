#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, ans = 0, a[100001], j, t = 0, k;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll dp[n + 1];
    ans = n;
    for (i = 2; i <= n; i++)
    {
        t = 0;
        dp[0] = 0;
        for (j = 0; j + i - 1 < n; j++)
        {

            if (a[j + i - 1] % i == 0)
            {
                t++;
                dp[j + i - 1] = t % mod;
            }
            else
            {
                dp[j + i - 1] = dp[j + i - 2] % mod;
            }
        }
        for (j = 0; j + i - 1 < n; j++)
        {
            if ((j + i - 1) >= n)
            {
                break;
            }
            ans += (dp[n - 1] - dp[j]) % mod;
        }
        for (j = 0; j < n; j++)
        {
            dp[j] = 0;
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
