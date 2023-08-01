#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n;

    cin >> n;
    ll dp[n + 1];
    vector<ll> coins{1, 5, 10, 20, 100};
    for (ll i = 0; i <= n; i++)
    {
        dp[i] = 30;
    }
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll x : coins)
        {
            if (i >= x)
                dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    }

    cout << dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
