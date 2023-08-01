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
    vector<ll> ha(n, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
            ha[i] = ha[i - 1] + a[i];
        else
            ha[i] = (a[i]);
    }
    ll ans = 0, mans = INT_MIN;
    for (i = -1; i < n; i++)
    {
        ans = 0;
        if (i != -1)
            ans += (ha[i] - ((i + 1) * k));
        for (ll j = i + 1; j < min(n, (i + 32)); j++)
        {
            ans += (a[j] / (1 << (j - i)));
        }
        mans = max(ans, mans);
    }

    cout << mans << "\n";
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
