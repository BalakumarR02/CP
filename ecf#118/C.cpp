#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, h, a[200], x, p = 0;

    cin >> n >> h;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {

        a[i] = a[i + 1] - a[i];
    }
    sort(a, a + n - 1);
    x = 0;
    for (i = 0; i < n - 1; i++)
    {
        x = p;
        x += (n - i) * a[i];
        if (h <= x)
        {
            break;
        }

        p += a[i];
    }
    x = (ll)ceil((double)(h - p) / (n - i));
    cout << x << endl;
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
