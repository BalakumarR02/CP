#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[3];

    cin >> a[0] >> a[1] >> a[2];
    n = (a[0] + a[2]) - (2 * a[1]);
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (abs(n) % 3 == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
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
