#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, a[100001], x;

    cin >> n;
    ll ha[n + 1];
    memset(ha, 0, sizeof(ha));
    vector<ll> v, v1;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n && ha[a[i]] == 0)
        {
            ha[a[i]] = 1;
        }
        else
        {
            x = (a[i] - 1) / 2;
            v1.push_back(x);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ha[i + 1] != 1)
            v.push_back(i + 1);
    }
    sort(v1.begin(), v1.end());
    for (i = 0; i < v1.size(); i++)
    {
        if (v1[i] < v[i])
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << v1.size() << "\n";
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
