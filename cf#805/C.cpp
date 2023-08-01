#include <bits/stdc++.h>
#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    vector<ll> a(n);
    unordered_map<ll, pair<ll, ll>> mp;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!(mp[a[i]].first))
        {
            mp[a[i]] = make_pair(i + 1, i + 1);
        }
        else
        {
            mp[a[i]].second = i + 1;
        }
    }
    while (k--)
    {
        ll x, y;
        cin >> x >> y;
        if (!mp[x].first || !mp[y].first)
        {
            cout << "NO\n";
            continue;
        }
        ll z = mp[y].second;
        if (mp[x].first < (z))
            cout << "YES\n";
        else
            cout << "NO\n";
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
