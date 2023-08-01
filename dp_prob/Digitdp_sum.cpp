#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;
ll dp[101][201][2];

int solve(string s, ll n, ll x, ll tight)
{
    if (x < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        if (x == 0)
            return 1;
        return 0;
    }
    if (dp[n][x][tight] != -1)
    {
        return dp[n][x][tight];
    }
    ll ub = tight ? (s[(s.length() - n)] - '0') : 9;
    ll ans = 0;
    for (ll dig = 0; dig <= ub; dig++)
    {
        ans += (solve(s, n - 1, x - dig, (tight & (ub == dig))));
    }
    return dp[n][x][tight] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll n, i, x;
    string s;
    cin >> n >> s >> x;
    cout << solve(s, n, x, 1);

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
