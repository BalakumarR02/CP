#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    int n, i;

    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "0";
        return;
    }
    sum /= 2;
    int dp[n + 1][sum + 1];
    dp[0][0] = 1;
    for (i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                int op1 = (i > j) ? 0 : dp[i - 1][j - i];
                int op2 = dp[i - 1][j];
                dp[i][j] = (op1 + op2) % mod;
            }
        }
    }
    cout << dp[n][sum];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
