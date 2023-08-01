#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a, b, m;

    cin >> a >> b;
    n = (a + b) / 4;
    m = min(a, b);
    if (m >= n)
    {
        cout << n << endl;
    }
    else
    {
        cout << m << endl;
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
