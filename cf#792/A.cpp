#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], k;

    cin >> n >> k;
    ll diff = 0;
    map<ll, ll> h;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!h[a[i]])
            diff++;
        h[a[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        if (!h[i])
        {
            break;
        }
    }
    ll mex = i;
    if (diff <= mex)
    {
        cout << 0 << "\n";
        return;
    }
    sort(a, a + n);

    for (i = 0; i < n; i++)
    {
        if (!h[i])
        {
            break;
        }
    }

    cout << diff - mex << "\n";
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
