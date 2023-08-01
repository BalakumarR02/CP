#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, m, r, c, i, j, ans = -1, w = 0;

    cin >> n >> m >> r >> c;
    string a[51];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            if (a[i][j] == 'B')
            {
                if (((i + 1) == r && (j + 1) == c))
                {
                    cout << 0 << "\n";
                    return;
                }
                else if (((i + 1) == r || (j + 1) == c))
                {

                    ans = 1;
                }
                if (ans != 1)
                    ans = 2;
            }
        }
    }
    cout << ans << "\n";
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
