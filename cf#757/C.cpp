#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, m, l, r, x, p;

    cin >> n >> m;
    p = 0;
    for (i = 0; i < m; i++)
    {
        cin >> l >> r >> x;
        p = p | x;
    }
    x = 1;
    for (i = 1; i < n; i++)
    {
        x = ((x % mod) * 2) % mod;
    }
    cout << ((x) % mod * p % mod) % mod << endl;
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
