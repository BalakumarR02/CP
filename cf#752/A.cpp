#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[102];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= (i + 1);
    }
    sort(a, a + n);
    cout << a[n - 1] << endl;
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
