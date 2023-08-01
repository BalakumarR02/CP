#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool rec(string s[], ll n, ll i, ll j, ll cb)
{
    if (i < 0 || i >= 2 || j < 0 || j >= n || s[i][j] == 'W')
        return false;
    cb--;
    if (cb == 0)
        return true;
    s[i][j] = 'W';
    return rec(s, n, i + 1, j, cb) || rec(s, n, i - 1, j, cb) || rec(s, n, i, (j + 1), cb);
}
void solve()
{
    ll n, i, cb = 0;

    cin >> n;
    string s[2], s1[2];
    for (i = 0; i < 2; i++)
    {
        cin >> s[i];
        s1[i] = s[i];
    }
    for (i = 0; i < 2; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (s[i][j] == 'B')
                cb++;
        }
    }
    if (rec(s1, n, 0, 0, cb) || rec(s, n, 1, 0, cb))
        cout << "YES\n";
    else
        cout << "NO\n";
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
