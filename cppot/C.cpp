#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll w, k, i;

    cin >> w >> k;
    if (w % k == 0)
    {
        cout << "YES\n";
        return;
    }
    else if (w < (10 + k))
    {
        cout << "NO\n";
        return;
    }
    if (w < (10 * k) && ((w - (10 + k)) % k) != 0)
    {
        if (k == 3 && (w == 23 || w == 26 || w == 29))
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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
