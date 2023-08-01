#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, ans = 0, a[200001], sum, k;

    map<ll, ll> m;
    cin >> n;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if ((2 * sum) % n != 0)
    {
        cout << 0 << endl;
        return;
    }
    k = (2 * sum) / n;
    for (i = 0; i < n; i++)
    {

        ans += m[k - a[i]];
        m[a[i]]++;
    }
    cout << ans << endl;
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
