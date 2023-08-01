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
    ll x = b - a, ans, b1, a1, n;

    ans = (x);
    if ((b | a) == b)
    {
        cout << 1 << "\n";
        return;
    }
    b1 = b, a1 = a;
    n = log2(b);
    ll j;
    for (j = a; j < b; j++)
    {
        ll x1 = 0;
        for (i = 0; i <= n; i++)
        {
            if (b & (1 << i))
            {
                x1 = (x1 | (1 << i));
            }
            if (x1 >= j)
                break;
        }
        ans = min(ans, (x1 - j + 1 + (j - a)));
    }
    ll x1 = 0;
    n = log2(a);
    for (i = 0; i <= n; i++)
    {
        if (b & (1 << i))
        {
            x1 = (x1 | (1 << i));
        }
    }
    if (x1 <= a)
        ans = min(a - x1 + 1, ans);

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
