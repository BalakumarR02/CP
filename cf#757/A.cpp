#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, l, r, k, i, a[102], m, p;

    cin >> n >> l >> r >> k;
    p = n;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        if (m < l || m > r)
        {
            a[i] = 1e9 + 1;
            p--;
            continue;
        }
        a[i] = m;
    }
    sort(a, a + n);
    for (i = 0; i < p; i++)
    {
        k -= a[i];
        if (k < 0)
        {
            break;
        }
    }
    cout << i << endl;
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
