#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, a, b, v[100001], j;

    cin >> n >> a >> b;
    if (abs(a - b) > 1 || (a + b) > (n - 2))
    {
        cout << -1 << endl;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        v[i] = i;
    }
    if (a < b)
    {
        for (i = 1; i <= n && b != 0; i += 2)
        {
            swap(v[i], v[i + 1]);
            b--;
        }
    }
    else if (a > b)
    {
        for (i = n; i >= 1 && a != 0; i -= 2)
        {
            swap(v[i], v[i - 1]);
            a--;
        }
    }
    else
    {
        if (b != 0)
        {
            swap(v[1], v[2]);
            swap(v[n], v[n - 1]);
            b--;
        }
        for (i = 3; i <= n && b != 0; i += 2)
        {
            swap(v[i], v[i + 1]);
            b--;
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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
