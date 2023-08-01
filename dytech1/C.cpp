#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, r[3], c[3], x, y;

    cin >> n;
    for (i = 0; i < 3; i++)
    {
        cin >> r[i] >> c[i];
    }
    cin >> x >> y;
    ll cr, cc;
    if (r[0] == r[1] || r[0] == r[2])
    {
        cr = r[0];
    }
    else
    {
        cr = r[1];
    }
    if (c[0] == c[1] || c[0] == c[2])
    {
        cc = c[0];
    }
    else
    {
        cc = c[1];
    }
    if ((cc == n || cc == 1) && (cr == n || cr == 1))
    {
        if (x == cr || y == cc)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
        return;
    }
    if ((x % 2 == cr % 2) || (y % 2 == cc % 2))
    {
        cout << "YES\n";
    }
    else
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
