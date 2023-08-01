#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a, b, c, d;

    cin >> a >> b >> c >> d;
    if (a == 0 || c == 0)
    {
        if (a == 0 && c == 0)
        {
            cout << "0\n";
            return;
        }
        else
        {
            cout << "1\n";
            return;
        }
    }
    ll gcd1 = __gcd(a, b), gcd2 = __gcd(c, d);
    a /= gcd1, b /= gcd1, c /= gcd2, d /= gcd2;
    if (a == c && b == d)
    {
        cout << "0\n";
        return;
    }
    a *= d;
    c *= b;
    if (((a % c == 0) || (c % a == 0)))
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
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
