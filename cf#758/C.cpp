#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.first > b.first;
}
void solve()
{
    ll n, i, j, x;

    cin >> n;
    ll c[n + 1], t = 0;
    memset(c, 0, sizeof(c));
    vector<pair<ll, ll>> a, b;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(make_pair(x, i));
    }
    for (i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
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
