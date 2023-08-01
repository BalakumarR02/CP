#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[101], b[101], m = 0, sum = 0;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
        sum += b[i];
    }
    ll sq = 0;
    for (i = 1; i <= n; i++)
    {
        sq += (a[i] * a[i] + b[i] * b[i]);
    }
    sq *= (n - 2);
    ll j, N = 10000;
    ll dp[2][10006];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= N; j++)
        {
            dp[i % 2][j] = 0;
            if (j >= a[i] && dp[(i - 1) % 2][j - a[i]])
            {
                dp[i % 2][j] = 1;
            }
            if (j >= b[i] && dp[(i - 1) % 2][j - b[i]])
            {
                dp[i % 2][j] = 1;
            }
        }
    }
    ll ans = 1e17;
    for (i = 0; i <= N; i++)
    {
        if (dp[n % 2][i])
        {
            ll s1, s2;
            s1 = i, s2 = sum - i;
            ll each = (s1 * s1 + s2 * s2);
            ans = min(ans, each);
        }
    }
    ans += sq;
    cout << ans << "\n";
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

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
