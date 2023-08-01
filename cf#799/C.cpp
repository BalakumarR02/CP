#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s[9];
    for (i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    ll j, k, x = -1;

    for (i = 0; i < 8; i++)
    {
        ll c = 0;
        for (j = 0; j < 8; j++)
        {
            if (s[i][j] == '#')
            {
                c++;
                k = j;
            }
        }
        if (c == 2)
            x = 1;
        if (c == 1 && x != -1)
            break;
    }

    cout << i + 1 << " " << k + 1 << "\n";
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
