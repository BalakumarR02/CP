#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, i, j, l, r, diff = 0, ans;
    string s, perm = "abc";

    cin >> n >> m;
    ll a[6][n + 1];
    cin >> s;
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < n; i++)
        {
            a[diff][i + 1] = a[diff][i] + (s[i] != perm[i % 3]);
        }
        diff++;

        next_permutation(perm.begin(), perm.end());
    }

    for (i = 0; i < m; i++)
    {
        cin >> l >> r;
        ans = n;
        for (j = 0; j < 6; j++)
        {
            ans = min(ans, a[j][r] - a[j][l - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
