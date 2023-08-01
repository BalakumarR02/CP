#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool ok(ll x, ll a[], ll s, ll n)
{
    ll p = 0;
    for (ll i = 1; i <= n && x <= n; i++, x++)
    {

        if ((a[x] - a[i - 1]) == s)
        {
            return true;
        }
        p = max((a[x] - a[i - 1]), p);
    }
    if (p < s)
        return true;
    return false;
}
void solve()
{
    ll n, i, a[200001] = {0}, sum = 0, s;

    cin >> n >> s;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (a[n] < s)
    {
        cout << "-1\n";
        return;
    }
    else if (a[n] == s)
    {
        cout << "0\n";
        return;
    }
    ll mop = 1e9;

    ll l = -1, r = n + 1, pos = -1;
    while (r - l != 1)
    {
        ll mid = l + r >> 1;
        if (ok(mid, a, s, n))
        {
            pos = mid;
            l = mid;
        }
        else
            r = mid;
        if (l != -1)
        {
            mop = min(mop, n - l);
        }
    }

    cout << mop << "\n";
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
