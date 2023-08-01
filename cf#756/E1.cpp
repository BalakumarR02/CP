#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, k, x[200002], i, u, v;

    cin >> n >> k;
    vector<ll> ed[n + 1];
    for (i = 1; i <= k; i++)
    {
        cin >> x[i];
    }
    for (i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for (i = 1; i <= n - 1; i++)
    {
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
