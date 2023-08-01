#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll a, b, i;

    cin >> a >> b;
    ll x = b - a, ans, n;

    ans = (x);
    if ((b | a) == b)
    {
        cout << 1 << "\n";
        return;
    }

    ll j;
    for (j = a; j < b; j++)
    {
        ll x1 = 0;
        for (i = 21; i >= 0; i--)
        {
            if (((1 << i) & b))
            {
                x1 = x1 ^ (1 << i);
            }
            else
            {
                if (((1 << i) & j))
                {
                    x1 = x1 ^ (1 << i);
                    break;
                }
            }
        }
        ans = min(ans, j - a - b + (j | x1) + 1);
    }

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
