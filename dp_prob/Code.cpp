#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i, low, high;

    cin >> n >> low >> high;
    int dp[n + 1][2];
    ll odd = 0, even = 0;
    for (i = low; i <= high; i++)
    {
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
    dp[1][0] = even;
    dp[1][1] = odd;
    for (i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][1] * odd + dp[i - 1][0] * even) % mod;
        dp[i][1] = (dp[i - 1][0] * odd + dp[i - 1][1] * even) % mod;
    }

    cout << dp[n][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
