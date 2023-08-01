#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s;

    cin >> n >> s;
    ll on = 0, ze = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            on++;
        }
        else
        {
            ze++;
        }
    }
    ll ans = max(1LL, ze) * max(1LL, on);
    ll cont = 0, mcont = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (i > 0 && s[i - 1] == '0')
            {
                mcont = max(cont, mcont);
                cont = 0;
            }
            cont++;
        }
        else
        {
            if (i > 0 && s[i - 1] == '1')
            {
                mcont = max(cont, mcont);
                cont = 0;
            }
            cont++;
        }
    }
    mcont = max(cont, mcont);

    cout << max(mcont * mcont, ans) << "\n";
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
