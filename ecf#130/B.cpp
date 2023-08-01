#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, q, p[200001], j;

    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    reverse(p + 1, p + n + 1);
    for (i = 1; i <= n; i++)
    {
        p[i] += p[i - 1];
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll s = 0, t = 0;

        cout << p[x] - p[x - y] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
