#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, l, r, k, x;

    cin >> l >> r >> k;
    if (l == r)
    {
        if (l == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
        return;
    }
    n = ((r - l + 1));
    x = (n + 1) / 2;
    if (l % 2 == 0)
    {
        if (r % 2 == 0)
        {
            x--;
        }
    }

    if (k >= x)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
