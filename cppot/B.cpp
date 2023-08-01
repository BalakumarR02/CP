#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, i, a[100001];
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back((a[i]));
    }
    sort(v.begin(), v.end());
    ll x = 0, m = -1;
    for (i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
        v[i] += v[i - 1];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == v[i])
            x++;
    }

    cout << x << "\n";
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
