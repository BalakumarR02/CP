#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

int dp[21][(1 << 21)], cost[21][21];
int solve(int i, int mask, int &n)
{
    if (i == (n))
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {
            ans = min(ans, cost[j][i] + solve(i + 1, (mask ^ (1 << j)), n));
        }
    }
    return dp[i][mask] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << solve(0, (1 << n) - 1, n) << "\n";

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
