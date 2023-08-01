#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    ll x[3], y[3], m[3];
    for (i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (i = 0; i < 3; i++)
    {
        if ((y[i] - y[(i + 1) % 3]) == 0 || (x[i] - x[(i + 1) % 3]) == 0)
        {
            ans++;
        }
    }
    if (ans == 2)
        cout << "NO\n";
    else

        cout
            << "YES\n";
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
