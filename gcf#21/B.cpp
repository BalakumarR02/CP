#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001];

    cin >> n;
    ll ans = 0, x = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            x++;
    }

    a[0] = 0;
    a[n + 1] = 0;
    for (i = 1; i <= n + 1; i++)
    {
        if (a[i] != 0 && a[i - 1] == 0)
        {
            ans++;
        }
    }

    cout << min(ans, (ll)2) << "\n";
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
