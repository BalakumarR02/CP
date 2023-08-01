#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k, b[1001], c[1001];

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<pair<ll, ll>> p;
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ll x = 0, y = b[i];
        while (y != 1)
        {
            if (y % 2 != 0)
            {
                y -= 1;
            }
            else
            {
                y /= 2;
            }
            x++;
        }
        if (x == 0)
            ans += c[i];
        else if (x <= k)
            p.push_back({c[i], x});
    }
    sort(p.begin(), p.end());
    ll m = p.size();
    for (i = 1; i < m; i++)
    {
        p[i].first += p[i - 1].first;
        p[i].second += p[i - 1].second;
    }

    ll x = 0;
    for (i = m - 1; i >= 0; i--)
    {
        if (p[i].second <= k)
        {
            x = max(p[i].first, x);
        }

        for (ll j = i - 1; j >= 0; j--)
        {
            if ((p[i].second - p[j].second) <= k)
            {

                x = max(p[i].first - p[j].first, x);
            }
            else if ((p[i].second - p[j].second) > k)
                break;
        }
    }
    ans += x;
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
