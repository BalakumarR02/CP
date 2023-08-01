#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k[101], h[101];

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> k[i];

    for (i = 0; i < n; i++)
        cin >> h[i];
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        v.push_back(make_pair((k[i] - h[i] + 1), k[i]));
    }
    sort(v.begin(), v.end());
    ll x = 0, t = 0, ans = 0, m = (ll)v.size(), last = 0, y;

    for (i = 0; i < m; i++)
    {
        if (i > 0)
        {
            if (v[i].first <= last)
            {
                if (v[i].second > last)
                {
                    t += (v[i].second - last);
                    y = x;
                    x = ((t * (t + 1) / 2));

                    last = v[i].second;
                    ans += (x - y);
                }

                continue;
            }
        }
        t = v[i].second - v[i].first + 1;
        x = t * (t + 1) / 2;
        ans += x;
        last = max(last, v[i].second);
    }
    cout << ans << "\n";
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
