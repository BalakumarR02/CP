#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    ll a[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll x = 0;
    if (k == 1)
    {
        cout << (n - 1) / 2 << "\n";
        return;
    }
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > (a[i - 1] + a[i + 1]))
        {
            x++;
        }
    }

    cout << x << "\n";
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
