#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, hc, dc, hm, dm, k, a, w;

    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    for (i = 0; i <= k; i++)
    {
        ll h = hc, d = dc;
        h += (i * a);
        d += ((k - i) * w);
        ll cs = hm / d, ms = h / dm;
        if (hm % d != 0)
        {
            cs++;
        }
        if (h % dm != 0)
        {
            ms++;
        }
        if (cs <= ms)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
