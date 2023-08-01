#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, m, i, j;

    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll sor = 0;
    while (sor < n && is_sorted(a[sor].begin(), a[sor].end()))
        sor++;
    if (sor == n)
    {
        cout << 1 << " " << 1 << "\n";
        return;
    }
    ll x = -1, y = -1;
    vector<ll> b = a[sor];
    sort(b.begin(), b.end());
    for (i = 0; i < m; i++)
    {
        if (b[i] != a[sor][i])
        {
            if (x == -1)
                x = i;
            else if (y == -1)
                y = i;
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        swap(a[i][x], a[i][y]);
        if (!is_sorted(a[i].begin(), a[i].end()))
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << x + 1 << " " << y + 1 << "\n";
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
