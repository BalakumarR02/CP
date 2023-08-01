#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> a(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for (i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            else
            {
                dp[i] = max(dp[i], 1);
            }
        }
    }
    int ans = -1;
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
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
