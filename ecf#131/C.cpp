#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
bool check(ll x, vector<ll> &v, ll n)
{
    ll i, xtra = 0;
    for (i = 0; i < n; i++)
    {
        xtra += max((v[i] - x), (ll)0);
        xtra -= max((x - v[i]) / 2, (ll)0);
    }
    if (xtra <= 0)
    {
        return true;
    }
    return false;
}
void solve()
{
    ll n, i, m;

    cin >> n >> m;
    vector<ll> v(n, 0);

    for (i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        v[x - 1]++;
    }
    ll l = 0, r = 2 * m;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid, v, n))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l << "\n";
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
