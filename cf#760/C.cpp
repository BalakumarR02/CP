#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, j, a[101], g1 = 0, g2 = 0, f = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    g1 = a[0];
    g2 = a[1];
    for (i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            g1 = __gcd(a[i], g1);
        }
        else
        {
            g2 = __gcd(a[i], g2);
        }
    }
    for (i = 0; i < n; i += 2)
    {
        if (a[i] % g2 == 0)
        {
            f = 1;
            break;
        }
    }
    if (f != 1)
    {
        cout << g2 << "\n";
        return;
    }
    f = 0;
    for (i = 1; i < n; i += 2)
    {
        if (a[i] % g1 == 0)
        {
            f = 1;
            break;
        }
    }
    if (f != 1)
    {
        cout << g1 << "\n";
        return;
    }
    else
    {
        cout << 0 << "\n";
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
