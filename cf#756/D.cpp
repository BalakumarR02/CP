#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, root, b[200002], p[200002], s[200002];

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] == (i))
        {
            root = i;
        }
        s[i] = -1;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    if (p[1] != root)
    {
        cout << -1 << endl;
        return;
    }
    s[root] = 0;
    for (i = 2; i <= n; i++)
    {
        if (s[b[p[i]]] == -1)
        {
            cout << -1 << endl;
            return;
        }
        s[p[i]] = s[p[i - 1]] + 1;
    }
    for (i = 1; i <= n; i++)
    {
        cout << s[i] - s[b[i]] << " ";
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
