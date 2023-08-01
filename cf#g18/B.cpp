#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
ll p[19][200001] = {0};
void precomp()
{
    // for (i = 0; i < 18; i++)
    // {
    //     for (m = l; m <= r; m++)
    //     {
    //         a += (m & (1 << i)) != 0;
    //         cout << a << " ";
    //     }
    //     ans = max(a, ans);
    //     cout << " " << ans << " ";
    //     a = 0;
    // }
    ll i, j;
    for (i = 0; i <= 18; i++)
    {
        for (j = 1; j < 200001; j++)
        {
            p[i][j] += ((j & (1 << i)) != 0) + p[i][j - 1];
        }
    }
}
void solve()
{
    ll n, ans = 0, l, r, i;

    cin >> l >> r;
    for (i = 0; i <= 18; i++)
    {
        ans = max(ans, (p[i][r] - p[i][l - 1]));
    }
    cout << r + 1 - l - ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    precomp();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
