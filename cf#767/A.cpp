#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k, a[101], b[101];

    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
    {
        v.push_back(make_pair(a[i], b[i]));
    }

    sort(v.begin(), v.end());
    ll s = k;
    for (i = 0; i < n; i++)
    {
        if (v[i].first <= s)
        {
            s += v[i].second;
        }
        else
        {
            break;
        }
    }
    cout << s << "\n";
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
