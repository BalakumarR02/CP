#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    vector<pair<ll, ll>> comb;
    vector<ll> h, p;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.push_back(x);
    }
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        p.push_back(x);
    }
    for (i = 0; i < n; i++)
    {
        comb.push_back({h[i], p[i]});
    }
    sort(comb.begin(), comb.end());
    for (i = 0; i < n; i++)
    {
        h[i] = comb[i].first;
        if (i > 0)
            p[n - i - 1] = min(comb[n - i - 1].second, p[n - i]);
        else
            p[n - i - 1] = comb[n - i - 1].second;
    }
    i = 0;
    ll ink = k;
    while (k > 0 && i < n)
    {
        auto itr = upper_bound(h.begin(), h.end(), ink);
        i = itr - h.begin();
        // cout << i << " " << ink << "  ";
        if (i >= n)
            break;
        k -= p[i];
        // cout << k << " " << comb[i].first << " " << comb[i].second << "  ";

        ink += k;
    }
    if (i >= n)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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
