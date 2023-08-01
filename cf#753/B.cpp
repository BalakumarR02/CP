#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, x, t;

    cin >> x >> n;
    if (n % 4 == 1)
    {
        t = -n;
    }
    else if (n % 4 == 2)
    {
        t = 1;
    }
    else if (n % 4 == 3)
    {
        t = n + 1;
    }
    else
    {
        t = 0;
    }
    if (x % 2 == 0)
    {
        cout << t + x << endl;
    }
    else
    {
        cout << x - t << endl;
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
