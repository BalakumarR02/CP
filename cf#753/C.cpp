#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[200001], p = 0, ma;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    ma = a[0];
    for (i = 0; i < n; i++)
    {
        a[i] -= p;
        ma = max(ma, a[i]);
        p += a[i];
    }
    cout << ma << endl;
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
