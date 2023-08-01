#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[200001], m = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    if (m == a[n - 1] || m == a[0])
    {
        for (i = n - 1; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
