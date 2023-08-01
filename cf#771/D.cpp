#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> v[n + 1];
    vector<pair<ll, ll>> first;
    for (i = 0; i < n; i++)
    {
        ll k = 0;
        for (ll j = 0; j < 5; j++)
        {
            ll x;
            cin >> x;
            v[i].push_back(x);
            if (i > 0)
            {
                if (v[0][j] > v[i][j])
                {
                    k++;
                }
            }
        }
        if (k >= 3)
        {
            first.push_back({k, i});
        }
    }
    if (first.empty())
    {
        cout << 1 << "\n";
        return;
    }
    sort(first.begin(), first.end());
    ll sz = first.size(), x = first[sz - 1].second;
    for (i = sz - 2; i >= 0; i--)
    {
        ll k = 0;
        for (ll j = 0; j < 5; j++)
        {
            if ()
        }
    }
    cout << x + 1 << "\n";
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

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
