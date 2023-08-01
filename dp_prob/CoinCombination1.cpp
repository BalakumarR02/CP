#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007;

using namespace std;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;

    cin >> n >> x;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int dp[x + 1];
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (int coin_value : v)
        {
            if (coin_value <= i)
            {
                dp[i] += (dp[i - coin_value]);
                dp[i] %= mod;
            }
        }
    }

    cout << dp[x];
}
int main()
{
    solve();
    return 0;
}
