#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m, a[200001], b;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    ll x = 0;
    for (i = 0; i < m; i++)
    {
        cin >> b;
        x = ((b + x) % n);
    }
    cout << a[x] << "\n";
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
