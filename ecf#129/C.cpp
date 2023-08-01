#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], b[200001], j;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> p;
    for (i = 0; i < n; i++)
    {
        p.push_back({a[i], b[i]});
    }

    sort(a, a + n);
    sort(b, b + n);
    vector<pair<ll, ll>> ans;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (p[j] == make_pair(a[i], b[i]))
            {
                swap(p[i], p[j]);
                if (i != j)
                {
                    ans.push_back({i + 1, j + 1});
                }
                break;
            }
        }
        if (j == n)
        {
            cout << "-1\n";
            return;
        }
    }

    ll k = (ll)ans.size();
    if (k <= 1e4)
    {
        cout << k << "\n";
        for (i = 0; i < k; i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
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
