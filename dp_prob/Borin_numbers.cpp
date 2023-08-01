#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
ll dp[50][2];
ll solve(string s, ll n, ll lea, ll tight)
{

    if (n == 0)
    {
        return 1;
    }

    ll ub = tight ? (s[s.length() - n] - '0') : 9;
    ll ans = 0;
    for (ll dig = 0; dig <= ub; dig++)
    {
        if (lea % 2 == 0)
        {
            if (n % 2 == ((dig % 2)))
            {
                ans += solve(s, n - 1, 0, (tight & (dig == ub)));
            }
        }
        else if (n % 2 == ((dig % 2)))
        {
            ans += solve(s, n - 1, lea, (tight & (dig == ub)));
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;

    for (ll i = 1; i <= t; i++)
    {
        string r, l;
        ll l1;
        cin >> l1 >> r;
        l = to_string(l1 - 1);
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << i << ": ";
        ll ans = solve(r, r.length(), 1, 1);
        memset(dp, -1, sizeof(dp));
        cout << (ans - solve(l, l.length(), 1, 1)) << "\n";
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
