#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 998244353;
const ll N = 1e6;
ll fact[N + 1], inv_fact[N + 1];

ll pow_mod(ll x, ll n)
{
    ll y = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            y = y * x % mod;
        }
        n /= 2;
        x = x * x % mod;
    }
    return y;
}
void fact_mod()
{
    fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
    for (ll i = 2; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = (inv_fact[i - 1] * pow_mod(i, mod - 2)) % mod;
    }
}

void solve()
{
    ll n, i;

    cin >> n;
    ll dp[n + 1];
    dp[1] = 1, dp[2] = 2;
    for (i = 3; i <= n; i++)
    {
        dp[i] = i * (dp[i - 1] + fact[i - 1] - 1) % mod;
        dp[i] %= mod;
    }
    cout << dp[n] % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact_mod();
    solve();

    return 0;
}
