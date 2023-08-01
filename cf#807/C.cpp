#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, c, q, n1;
    string s;
    cin >> n >> c >> q >> s;
    n1 = n;
    map<ll, pair<ll, ll>> mp;
    while (c--)
    {
        ll l, r;
        cin >> l >> r;
        mp[n1] = make_pair(l, r);
        n1 += (r - l + 1);
    }
    while (q--)
    {
        ll l;
        cin >> l;
        while (l > n)
        {
            auto it = mp.lower_bound(l);
            it--;
            ll p = (l - (it->first));
            auto k = it->second;
            l = k.first;

            ll r = k.second;
            l = (l + p - 1);
        }
        cout << s[l - 1] << "\n";
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
