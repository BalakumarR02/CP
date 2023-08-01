#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, a, b, c, i;

    cin >> a >> b >> c;

    if ((2 * b - a) % c == 0 && (2 * b - a) > 0)
    {
        cout << "YES\n";
    }
    else if ((2 * b - c) % a == 0 && (2 * b - c) > 0)
    {
        cout << "YES\n";
    }
    else if ((c + a) % (2 * b) == 0)
    {
        cout << "YES\n";
    }
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
