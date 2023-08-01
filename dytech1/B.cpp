#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, l, r;

    cin >> l >> r;
    ll left = (ll)sqrtl(l), right = (ll)sqrtl(r), ans = 0;

    ans = (right - left + 1) * 3;
    // cout << left << " " << right << " " << ans << " ";

    ll ls = left * left, rs = right * right;
    if (l > ls && l <= (ls + left))
    {
        ans--;
    }
    else if (l > (ls + left))
    {
        ans -= 2;
    }
    if (r < (rs + right))
    {
        ans -= 2;
    }
    else if (r >= (rs + right) && r < (rs + 2 * right))
    {
        ans -= 1;
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
