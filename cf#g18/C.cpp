#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, match = 0, nmatch = 0, o = 0, nnum[2] = {0}, ans = 1e9, j;
    string a, b;
    cin >> n;
    cin >> a >> b;
    rep(i, 0, n)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '1')
            {
                match++;
                j = i;
            }
        }
        else
        {
            nmatch++;
            if (a[i] == '1')
                nnum[1]++;
            else
                nnum[0]++;
        }
    }
    if (!nmatch)
    {
        cout << 0 << "\n";
        return;
    }
    if (nnum[1] == nnum[0])
    {
        ans = nmatch;
    }
    if (match)
    {
        match = nmatch = nnum[0] = nnum[1] = 0;
        rep(i, 0, n)
        {
            if (i != j)
            {
                if (a[i] == '1')
                    a[i] = '0';
                else
                    a[i] = '1';
            }
            if (a[i] == b[i])
            {
                match++;
            }
            else
            {
                nmatch++;
                if (a[i] == '1')
                    nnum[1]++;
                else
                    nnum[0]++;
            }
        }
        if (!nmatch)
        {
            cout << 1 << "\n";
            return;
        }
        if (nnum[1] == nnum[0])
        {
            ans = min(nmatch + 1, ans);
        }
    }
    if (ans == 1e9)
        ans = -1;
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
