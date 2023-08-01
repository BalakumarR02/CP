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
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x != 1)
            v.push_back({x, i});
    }
    if ((ll)v.size() == 0)
    {
        cout << "0\n";
        return;
    }
    sort(v.begin(), v.end());
    vector<pair<ll, ll>> p;
    ll x = v[0].first;
    for (i = 1; i < (ll)v.size(); i++)
    {
        ll np = 0;
        if (v[i].first % x)
        {
            np = x - (v[i].first % x);
            p.push_back({v[i].second + 1, np});
        }
        x = np + v[i].first;
    }
    sort(p.begin(), p.end());
    cout << p.size() << "\n";
    for (i = 0; i < (ll)p.size(); i++)
    {
        cout << p[i].first << " " << p[i].second << "\n";
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

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
