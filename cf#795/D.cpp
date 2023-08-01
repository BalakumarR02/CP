#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i, a[200001];

    cin >> n;
    ll ma = -1e9 - 1;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    vector<ll> ind;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ma)
            ind.push_back(i);
        if (a[i] > 0 && a[i - 1] > 0 && i > 0)
        {
            cout << "NO\n";
            return;
        }
    }
    for (ll j = 0; j < (ll)ind.size(); j++)
    {
        vector<pair<ll, ll>> p;
        ll s = 0, maxel = -1e9 - 1;
        for (i = 0; i <= ind[j]; i++)
        {
            s += a[i];
        }
    }
    cout << "YES\n";
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
