#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    rep(i, 1, n + 1)
    {
        rep(x, 1, 7)
        {
            if (x <= i)
            {
                dp[i] = (dp[i] + dp[i - x]) % mod;
            }
            else
                break;
        }
    }
    cout << dp[n] % mod;

    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
