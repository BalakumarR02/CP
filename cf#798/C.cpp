#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool check(ll x, ll a[], ll n, ll d)
{
    ll f = a[0], c = 1;
    for (ll i = 1; i < n; i++)
    {
        if ((a[i] - f) >= x)
        {
            c++;
            f = a[i];
        }
    }
    if (c < d)
    {
        return true;
    }
    return false;
}
void solve()
{
    ll n, i, c, a[200001];

    cin >> n >> c;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll l = -1, r = 1e9 + 1;
    while (r - l != 1)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid, a, n, c))
        {
            r = mid;
        }
        else
            l = mid;
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
