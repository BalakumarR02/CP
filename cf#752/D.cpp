#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    long long n, i, x, y;

    cin >> x >> y;
    if (x <= y)
    {
        n = y - (y % x) / 2;
    }
    else
    {
        n = x + y;
    }
    cout << n << endl;
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
