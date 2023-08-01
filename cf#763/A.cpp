#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m, rb, cb, rd, cd, a1 = 0, a2 = 0;

    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb == rd || cd == cb)
    {
        cout << 0 << "\n";
        return;
    }
    a1 = rd - rb;
    a2 = cd - cb;
    if (rb > rd)
    {
        a1 = (n - rb) + (n - rd);
    }
    if (cb > cd)
    {
        a2 = (m - cb) + (m - cd);
    }
    cout << min(a1, a2) << "\n";
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
