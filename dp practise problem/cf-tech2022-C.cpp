/*Omkar and Determination


*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, m, i, j, q, x1, x2, ans = 0;

    cin >> n >> m;
    char a[n + 1][m + 1];
    ll b[m + 1];
    for (j = 0; j < m; j++)
    {
        b[j] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            cin >> a[i][j];
        }
    }

    for (ll j = 1; j < m; j++)
    {
        for (ll i = 1; i < n; i++)
        {

            if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
            {
                ans++;
            }
        }
        b[j] = ans;
    }

    cin >> q;
    while (q--)
    {
        cin >> x1 >> x2;

        if (b[x1 - 1] - b[x2 - 1] == 0)

        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
